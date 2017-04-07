
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
  drawbitmap(buffer, 0, 0, picture,50,64,1);
  drawstring(buffer,51,0,"ROBSON COUTO");

  drawstring(buffer,51,2,"Eng Eletrica");
  drawstring(buffer,51,4,"UFC");


  drawstring(buffer,51,6,"github:");
  drawstring(buffer,51,7,"@robsoncouto");
  write_buffer(buffer);
  while(01){
    if(button_pressed()){

      while (1) {
        for(int i=0;i<164;i=i+4){
          clear_buffer(buffer);
          drawbitmap(buffer, 0,  0, dragao+i,128,8,1);
          drawbitmap(buffer, 0,  8, dragao+1*292+i,128,8,1);//FIXME ugliest hack ever, not proud
          drawbitmap(buffer, 0, 16, dragao+2*292+i,128,8,1);
          drawbitmap(buffer, 0, 24, dragao+3*292+i,128,8,1);
          drawbitmap(buffer, 0, 32, dragao+4*292+i,128,8,1);
          drawbitmap(buffer, 0, 40, dragao+5*292+i,128,8,1);
          drawbitmap(buffer, 0, 48, dragao+6*292+i,128,8,1);
          drawbitmap(buffer, 0, 56, dragao+7*292+i,128,8,1);
          write_buffer(buffer);
          _delay_ms(300);
        }
      }

    }
  }
}
