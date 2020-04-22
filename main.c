#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

enum states { 
  GPIO_PORT_ON_FOR_2S,
  GPIO_PORT_OFF_1S,
  GPIO_PORT_ON_FOR_1S,
  GPIO_PORT_OFF_FOR_3S
};

enum states work_state = GPIO_PORT_ON_FOR_2S;
int s = 0;

while(1) {
  switch(work_state ) {
  case GPIO_PORT_ON_FOR_2S:
   	 led_on(); // make sure LED is on
    	if(s >= 1) {
      		work_state = GPIO_PORT_OFF_1S; // turn LED off on next round
      		s = 0;
    			}
    	break;
  case GPIO_PORT_OFF_1S:
   		 led_off(); // make sure LED is off
    		work_state = GPIO_PORT_ON_FOR_1S; // LED back on on next round
    	break;
  case GPIO_PORT_ON_FOR_1S:
    		led_on();
   		work_state =  GPIO_PORT_OFF_FOR_3S;
    		s = 0; // next work_state will need this again
    	break;
  case GPIO_PORT_OFF_FOR_3S:
    		led_off();
   		 if(s >= 2) {
      			work_state = LED_ON2S; // restart cycle on next round
      			s = 0;
    				}
    	break;
  }

  sleep(1); // sleep for a second
  s ++;}
