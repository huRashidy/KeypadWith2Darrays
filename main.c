
#include <stdint.h>
#include"keypad.h"
#include "gpio.h"
#include "stm32f4xx.h"

int main(void)
{

KeyPad_INIT();

while (1){
	KeyPad_MANAGE();
}

}
