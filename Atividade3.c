#include <at89x52.h>

int cont,camera;

void auxTimer() interrupt 1{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	
	cont++;
	if(cont == 1500){
		P2 = 0;
		camera++;
		camera%=4;
		cont = 0;
	}
	
	TR0 = 1;
}


void main(){

	EA = 1;
	ET0 = 1;
	TMOD = 1;
	TR0 = 1;
	
	P2 = 0;
	P3 = 0;
	camera = 0;
	cont = 0;
	while(1){
		if(P3_0 == 1){
			if(camera == 0){ 
				P2_0 = 1;
				P2_3 = 0;
			}
			else if(camera == 1){ 
				P2_1 = 1;
				P2_0 = 0;
			}
			else if(camera == 2){ 
				P2_2 = 1;
				P2_1 = 0;
			}
			else{ 
				P2_3 = 1;
				P2_2 = 0;
			}
		}
	}
}