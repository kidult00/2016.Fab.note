//
// hello.HC-SR04.c
//
// HC-SR04 sonar hello-world
//    9600 baud FTDI interface
//
// Neil Gershenfeld 11/15/15
// (c) Massachusetts Institute of Technology 2015
//
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose. Copyright is
// retained and must be preserved. The work is provided
// as is; no warranty is provided, and users accept all 
// liability.
//

#include <avr/io.h>
#include <util/delay.h>

#define output(directions,pin) (directions |= pin) // set port direction for output
#define set(port,pin) (port |= pin) // set port pin
#define clear(port,pin) (port &= (~pin)) // clear port pin
#define pin_test(pins,pin) (pins & pin) // test for port pin
#define bit_test(byte,bit) (byte & (1 << bit)) // test for bit set
#define bit_delay_time 102 // bit delay for 9600 with overhead
#define bit_delay() _delay_us(bit_delay_time) // RS232 bit delay
#define half_bit_delay() _delay_us(bit_delay_time/2) // RS232 half bit delay
#define char_delay() _delay_ms(10) // char delay

#define serial_port PORTB
#define serial_direction DDRB
#define serial_pin_out (1 << PB2)
#define trigger_port PORTB
#define trigger_direction DDRB
#define trigger_pin (1 << PB3)
#define echo_pins PINB
#define echo_direction DDRB
#define echo_pin (1 << PB4)

#define timeout 255

void put_char(volatile unsigned char *port, unsigned char pin, char txchar) {
   //
   // send character in txchar on port pin
   //    assumes line driver (inverts bits)
   //
   // start bit
   //
   clear(*port,pin);
   bit_delay();
   //
   // unrolled loop to write data bits
   //
   if bit_test(txchar,0)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,1)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,2)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,3)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,4)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,5)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,6)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,7)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   //
   // stop bit
   //
   set(*port,pin);
   bit_delay();
   //
   // char delay
   //
   bit_delay();
   }

int main(void) {
   //
   // main
   //
   static unsigned char high,low;
   //
   // set clock divider to /1
   //
   CLKPR = (1 << CLKPCE);
   CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
   //
   // initialize output pins
   //
   set(serial_port,serial_pin_out);
   output(serial_direction,serial_pin_out);
   clear(trigger_port,trigger_pin);
   output(trigger_direction,trigger_pin);
   //
   // start counter
   //
   TCCR0B |= (1 << CS00); // prescale /1
   //
   // main loop
   //
   while (1) {
      //
      // trigger pulse
      //
      set(trigger_port,trigger_pin);
      _delay_us(10);
      clear(trigger_port,trigger_pin);  
      //
      // wait for echo rising edge
      //
      high = 0;
      TCNT0 = 0;
      TIFR |= (1 << TOV0);
      while (1) {
         if ((echo_pins & echo_pin) != 0) // check for rising edge
            break;
         if ((TIFR & (1 << TOV0)) != 0) { // check for counter overflow
            high += 1;
            if (high == timeout)
               break;
            TIFR |= (1 << TOV0);
            }
         }
      //
      // rising edge found, wait for falling edge
      //
      high = 0;
      TCNT0 = 0;
      TIFR |= (1 << TOV0);
      while (1) {
         if ((echo_pins & echo_pin) == 0) { // check for falling edge
            low = TCNT0;
            break;
            }
         if ((TIFR & (1 << TOV0)) != 0) { // check for counter overflow
            high += 1;
            if (high == timeout)
               break;
            TIFR |= (1 << TOV0);
            }
         }
      //
      // send count with framing
      //
      put_char(&serial_port,serial_pin_out,1);
      put_char(&serial_port,serial_pin_out,2);
      put_char(&serial_port,serial_pin_out,3);
      put_char(&serial_port,serial_pin_out,4);
      put_char(&serial_port,serial_pin_out,low);
      put_char(&serial_port,serial_pin_out,high);
      //
      // delay before next cycle
      //
      _delay_ms(10);
      }
   }

