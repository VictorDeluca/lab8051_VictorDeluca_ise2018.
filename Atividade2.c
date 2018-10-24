#include <at89x52.h>

int cont,produtos,esteira;

void auxTimer() interrupt 1{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
	cont++;
	
	if(cont == 500){
		produtos++;
		if(produtos==1) P3_0 = 1;
		if(produtos==2) P3_1 = 1;
		if(produtos==3) P3_2 = 1;
		if(produtos==4) P3_3 = 1;
		
		if(produtos == 5){
			esteira++;
			esteira%=3;
			
			P2 = 0;
			P3 = 0;
			if(esteira == 0) P2_0 = 1;
			else if(esteira == 1) P2_1 = 1;
			else P2_2 = 1;
		}
		produtos%=5;
		cont = 0;
	}
}


void main(){
	EA = 1;
	ET0 = 1;
	TMOD = 1;
	TR0 = 1;
	
	esteira = 0;
	produtos = 0;
	cont = 0;
	P2 = 0;
	P3 = 0;
	P2_0 = 1;
	while(1){
		
	}
}