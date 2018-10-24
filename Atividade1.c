#include <at89x52.h>

int cont;

void auxTimer() interrupt 1{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
	cont++;
}

void main(){
	EA = 1;
	ET0 = 1;
	TMOD = 1;
	
	cont = 0;
	P2 = 0;
	P3 = 0;
	while(1){
		if(P3_0 == 1){
			while(P3_1 == 0 && P3_2 == 0);
			
			if(P3_1 == 1){
				P2_0 = 1;
			} else if(P3_2 == 1){
				P2_1 = 1;
			}
			TR0 = 1;
			while(cont < 500);
			
			cont = 0;
			P2 = 0;
			P3 = 0;
			TR0 = 0;
		}
	}
}