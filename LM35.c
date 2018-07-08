/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 7/8/2018
Author  : 
Company : 
Comments: 


Chip type               : ATmega16A
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16a.h>

#include <delay.h>
#include <stdio.h>
// Alphanumeric LCD functions
#include <alcd.h>
#include <eeprom.h>

//#include <avr/io.h>
//#include <avr/eeprom.h>

// Declare your global variables here
int max = 0, min = 0 , s = 0 , n = 0 , flag = 0 , flag2 = 0 , temprature , mp ;
char m1[20] , m2[20] , m3[20] ;
int maxfromEE = 0 , minfromEE = 0;  

//eeprom int alfa = 1;

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
// Place your code here

      s = 100 ;
      delay_ms(10);
   //  PORTC.4 = 1 ;
  //   PORTC.5 = 1 ;
    //  PORTC.6 = 1 ;
   //  PORTC.7 = 1 ;
      
      // Place your code here    
     // PORTC.4 = 0 ;   
       
      if (PINC.0 == 0) { 
        
        PORTC = 0b00011111 ;
        if ( PINC == 0b00011111 ) {
        n = 1 ;
        if (flag == 0 )   
            max = max * 10 + 1 ;
        else    
            min = min * 10 + 1 ;
        } 
        PORTC = 0b00001111 ;
        PORTC = 0b00101111 ;
        if ( PINC == 0b00101111 ) {
        n = 6 ;
        if (flag == 0 )   
            max = max * 10 + 6 ;
        else    
            min = min * 10 + 6 ;
        
        }  
        PORTC = 0b00001111 ;  
        PORTC = 0b01001111 ;
        if ( PINC == 0b01001111 ) {
        n = 7 ;
         if (flag == 0 )   
            max = max * 10 + 7 ;
        else    
            min = min * 10 + 7 ;
        
        }  
        
        PORTC = 0b00001111 ;
        PORTC = 0b10001111 ;
        if ( PINC == 0b10001111 ) {
        flag = 1   ;
        
        //max = max * 10 + 7 ;
        //min = min * 10 + 7 ;
        
        }  
        
        PORTC = 0b00001111 ;
        } 
        
        if (PINC.1 == 0) { 
        
        PORTC = 0b00011111 ;
        if ( PINC == 0b00011111 ) {
        n = 2 ;           
         if (flag == 0 )   
            max = max * 10 + 2 ;
        else    
            min = min * 10 + 2 ;
        } 
        PORTC = 0b00001111 ;
        PORTC = 0b00101111 ;
        if ( PINC == 0b00101111 ) {
        n = 5 ;           
         if (flag == 0 )   
            max = max * 10 + 5 ;
        else    
            min = min * 10 + 5 ;
        }  
        PORTC = 0b00001111 ;  
        PORTC = 0b01001111 ;
        if ( PINC == 0b01001111 ) {
        n = 8 ;           
       if (flag == 0 )   
            max = max * 10 + 8 ;
        else    
            min = min * 10 + 8 ;
        
        }  
        
        PORTC = 0b00001111 ;
        }
         
        if (PINC.2 == 0) { 
        
        PORTC = 0b00011111 ;
        if ( PINC == 0b00011111 ) {
        n = 3 ;           
         if (flag == 0 )   
            max = max * 10 + 3 ;
        else    
            min = min * 10 + 3 ;
        
        } 
        PORTC = 0b00001111 ;
        PORTC = 0b00101111 ;
        if ( PINC == 0b00101111 ) {
        n = 4 ;           
         if (flag == 0 )   
            max = max * 10 + 4 ;
        else    
            min = min * 10 + 4 ;
        
        }  
        PORTC = 0b00001111 ;  
        PORTC = 0b01001111 ;
        if ( PINC == 0b01001111 ) {
        n = 9 ;           
        if (flag == 0 )   
            max = max * 10 + 9 ;
        else    
            min = min * 10 + 9 ;
        
        }  
        
        PORTC = 0b00001111 ;
        PORTC = 0b10001111 ;
        if ( PINC == 0b10001111 ) {
        flag2 = 1   ;
        }
        
        PORTC = 0b00001111 ;
        }
}


// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}



void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=In Bit1=In Bit0=In 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=P Bit2=P Bit1=P Bit0=P 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (1<<PORTC3) | (1<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);

// Port D initialization
// Function: Bit7=Out Bit6=Out Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(1<<DDD7) | (1<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=0 Bit6=0 Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (1<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: Off
// INT2: Off
GICR|=(0<<INT1) | (1<<INT0) | (0<<INT2);
MCUCR=(0<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(0<<INTF1) | (1<<INTF0) | (0<<INTF2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);

// ADC initialization
// ADC Clock frequency: 15.625 kHz
// ADC Voltage Reference: AVCC pin
// ADC Auto Trigger Source: Free Running
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (1<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0);
SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTB Bit 1
// RD - PORTB Bit 2
// EN - PORTB Bit 3
// D4 - PORTB Bit 4
// D5 - PORTB Bit 5
// D6 - PORTB Bit 6
// D7 - PORTB Bit 7
// Characters/line: 8
lcd_init(8);

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here
      
      mp = read_adc(0);
     
      if (flag == 1) 
        eeprom_update_dword(2,max);
      if (flag2 == 1)
        eeprom_update_dword(6,min);
      
      
      max = eeprom_read_dword(2) ;
      min = eeprom_read_dword(6) ;
      
      sprintf(m1,"%d",max);   
      sprintf(m2,"%d",min);
      lcd_gotoxy(0,0);       
      lcd_puts(m1);
      lcd_gotoxy(0,1);
      lcd_puts(m2);
      
      temprature = mp / 2 ;
     // lcd_gotoxy(0,1);
     // sprintf(m3,"%d",temprature)   ;        
     // lcd_puts(m3);
      
      // if (temprature > max && flag == 1) {
      
      if (temprature > max ) {
        PORTD.6 = 1 ;
        PORTD.7 = 0;
      }
      
      if (temprature < min  ) {
        PORTD.6 = 0 ;
        PORTD.7 = 1 ;
      }
      
      if( temprature > min && temprature < max) {
      PORTD.6 = 0 ;
      PORTD.7 = 0;
      }             
      
       
      //PORTD.6 = 0 ;
      //PORTD.7 = 0;
                      
      //sprintf(m1,"%d",max);   
      //sprintf(m2,"%d",min);
      //lcd_gotoxy(0,0);       
      //lcd_puts(m1);
      //lcd_gotoxy(0,1);
      //lcd_puts(m2);
    
    
      }
}
