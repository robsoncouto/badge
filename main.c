
#define F_CPU 8000000UL

#include<avr/io.h>
#include <avr/wdt.h>
#include<util/delay.h>
#include "hardware.h"
#include "ST7565-T3/c/stlcd.h"
#include "ST7565-T3/c/glcd.h"
#include "pic.h"

//This is the buffer used to transfer data to the LCD
uint8_t buffer[128*64/8];
int main(void){
  init_hardware(); //low level atmega stuff (PORTS, ACD, etc)
  clear_screen();
  drawbitmap(buffer, 0, 0, picture,64,64,1);
  while(01);
}
