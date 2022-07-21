#include "gpio.h"
#include "keypad.h"
const int no_raws = 4;
#include "stm32f4xx.h"

const int no_cols = 3;
char rows[4]={3,4,5,6}; //fill the array
char cols[3]={0,1,2}; //fill the array

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array

char currentvalue=0;


void KeyPad_INIT(void)
{
	// set input and ouput pins
		// get pins from row and set it as input
		// get pins from cols and set it as output
	// hint use gpio driver functions
	for(int j =7 ; j<=10 ; j++){
	GPIO_Init (GPIOB,j,1,1);
	GPIO_Write(GPIOB,j,0);
	}
	for(int i = 0 ; i<=3 ; i++){
	 GPIO_Init (GPIOB,rows[i],0,1);
	}
	for(int i = 0 ; i<=2; i++){
		GPIO_Init (GPIOB,cols[i],1,1);
	}

}

void KeyPad_MANAGE(void)
{
	//nested for loop to check which button is pressed
	//if pressed wait until released then change the value;
	//call KeypadCallouts_KeyPressNotificaton
	//haroh l kol column of output akhaleh high a2ra el rows of input lw fehom high yb2a kda zorar etdaghat

	GPIO_Write(GPIOB,0,1);
	GPIO_Write(GPIOB,1,1);
	GPIO_Write(GPIOB,2,1);

	for(int i=0 ; i<=2; i++){
		GPIO_Write( GPIOB,cols[i],0);
		for(int j=0 ;j<=3 ; j++ ){
			if(GPIO_ReadPin(GPIOB,rows[j])==0){
				currentvalue=lookupTable[j][i];
				KeypadCallouts_KeyPressNotificaton();
			}
		}
		GPIO_Write( GPIOB,cols[i],1);


	}

}

char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{ 	int x = KeyPad_GET_VALUE();
		    GPIO_Write( GPIOB,7,(x&(1<<0))  >>0 );
			GPIO_Write(GPIOB,8,(x&(1<<1))  >>1 );
			GPIO_Write(GPIOB,9,(x&(1<<2))   >>2  );
			GPIO_Write(GPIOB,10,(x&(1<<3))   >>3  );
}




