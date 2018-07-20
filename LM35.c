/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
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
int  n = 0 , flag = 0 , flag2 = 0 ,flag3 = 2, flag5 = 0 , flag4 = 0, temprature , mp ,hu , h;
float humadity = 0 ;
unsigned int max = 0 , min = 0 , hmax = 0 , hmin = 0 ,maxee = 0 , minee = 0 , hmaxee = 0 , hminee = 0; 
int chap = 0 ;
char m1[20] , m2[20] ,m3[20] , m4[20] , m5[20] , m6[20] , m7[20];
 

//eeprom int alfa = 1;

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
// Place your code here\

        
      


     // key_interrupt = 1 ;

      if(PORTA.2 == 0){ 
        PORTA.2 = 1 ;
       // flagg = 1 ;
        }             

      else if(PORTA.2 == 1){ 
        PORTA.2 = 0 ;
        //flagg = 0 ;
        }

     
        
        //PORTC = 0b00001111 ;
        
     
           
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
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
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

//GICR&= ~ (1<<INT0);
//GICR|=(1<<INT0);


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
      // h = read_adc(7) ;
            
        
      
      temprature = mp / 2 ; 
      
     // humadity = ((h/205 - 0.6)/0.03) + 20 ;  
     // hu = (int) humadity ;
    //  lcd_gotoxy(0,0);
     // sprintf(m3,"%d",hu)   ;        
     // lcd_puts(m3);
     // lcd_gotoxy(0,0);
    //  sprintf(m5,"%d",h)   ;        
    //  lcd_puts(m5);
      
      sprintf(m5,"%d",temprature)   ;        
      lcd_gotoxy(0,0);
      lcd_puts(m5);
 
      if (temprature > maxee ) {
        PORTD.6 = 1 ;
        PORTD.7 = 0;
      }
      
      if (temprature < minee  ) {
        PORTD.6 = 0 ;
        PORTD.7 = 1 ;
      }
      
      if( temprature > minee && temprature < maxee) {
      PORTD.6 = 0 ;
      PORTD.7 = 0;
      }             
      
      if (h > maxee ) {
        PORTD.4 = 1 ;
        PORTD.5 = 0;
      }
      
      if (h < minee  ) {
        PORTD.4 = 0 ;
        PORTD.5 = 1 ;
      }
      
      if( h > minee && h < maxee) {
      PORTD.4 = 0 ;
      PORTD.5 = 0;
      }             

    
        PORTC = 0b11101111;
        if (PINC.0 == 0) {
        n = 3 ;
        if (flag == 0 )   
            max = max * 10 + 3 ;
        else  
            min = min * 10 + 3 ;   
            
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 3 ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10 + 3 ;           
        }
            
        else if (PINC.1 == 0) {
        n = 4 ;
        if (flag == 0 )   
            max = max * 10 + 4 ;
        else    
            min = min * 10 + 4 ;  
        
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 4 ;
//        else if (flag3 == 1 )  
//            hmin = hmin * 10 + 4 ;                
        }
            
        else if (PINC.2 == 0) {
        n = 7 ;
        if (flag == 0 )   
            max = max * 10 + 7 ;
        else  
            min = min * 10 + 7 ; 
            
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 7 ;
//        else if (flag3 == 1 )  
//            hmin = hmin * 10 + 7 ;             
        }
            
        else if (PINC.3 == 0) { 
            //chap = 1 ;
            //n = 11 ;
            flag = 1   ; 
           // flag3 = 1 ;
            
        }
            
        PORTC = 0b11011111;
            
        if (PINC.0 == 0) {
        n = 1 ;
        if (flag == 0 )   
            max = max * 10 + 1 ;
        
        else   
            min = min * 10 + 1 ;  
            
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 1 ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10 + 1 ;                
        }
            
        else if (PINC.1 == 0) {
        n = 5 ;
        if (flag == 0 )   
            max = max * 10 + 5 ;
        else     
            min = min * 10 + 5 ;
        
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 5 ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10 + 5 ;                  
        
        }
            
        else if (PINC.2 == 0) {
        n = 8 ;
        if (flag == 0 )   
            max = max * 10 + 8 ;
        else    
            min = min * 10 + 8 ;
            
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 8 ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10 + 8 ;                  
        }
            
        else if (PINC.3 == 0) {
        n = 0 ;
        if (flag == 0 )   
            max = max * 10 ;
        else    
            min = min * 10  ;
        
//        if (flag3 == 0 )   
//            hmax = hmax * 10  ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10  ;                  
        } 
                   
        PORTC = 0b10111111;
        if (PINC.0 == 0) {
        n = 2 ;
        if (flag == 0 )   
            max = max * 10 + 2 ;
        else     
            min = min * 10 + 2 ;
//        
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 2 ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10 + 2 ;                  
        }
            
        else if (PINC.1 == 0) {
        n = 6 ;
        if (flag == 0 )   
            max = max * 10 + 6 ;
        else     
            min = min * 10 + 6 ;
            
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 6 ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10 + 6 ;                  
        }
            
        else if (PINC.2 == 0) {
        n = 9 ;
        if (flag == 0 )   
            max = max * 10 + 9 ;
        else   
            min = min * 10 + 9 ;
//        
//        if (flag3 == 0 )   
//            hmax = hmax * 10 + 9 ;
//        else if (flag3 == 1 )    
//            hmin = hmin * 10 + 9 ;                  
        }
            
        else if (PINC.3 == 0) {
      
        chap = 1 ;
        n = 10 ;
        flag2 = 1   ; 
      //  flag3 = 0 ;
       // flag4 = 1 ;
            
        }
        delay_ms(300) ;
        PORTC = 0b00001111 ;
           
//     if(chap == 1 ) {
//     sprintf(m1,"%d",max);   
//     sprintf(m2,"%d",min);
//     lcd_gotoxy(0,1);       
//     lcd_puts(m1); 
//     lcd_gotoxy(5,1);
//     lcd_puts(m2); 
//     sprintf(m6,"%d",hmax);   
//     sprintf(m7,"%d",hmin);
//     lcd_gotoxy(1,8);       
//     lcd_puts(m6); 
//     lcd_gotoxy(1,12);
//     lcd_puts(m7); 
       
     chap = 0 ;  
//     }
     
//     if (flag == 1 && flag2 == 1)   {
//      max = eeprom_read_dword(2) ;
//      min = eeprom_read_dword(6) ;
//      flag = 0 ;
//      flag2 =  0 ;
//      } 

     if (flag == 1) 
        eeprom_update_dword(0,max);
     if (flag2 == 1)
        eeprom_update_dword(4,min);
     
      
      maxee = eeprom_read_dword(0) ;
      minee = eeprom_read_dword(4) ;
       
        
     sprintf(m6,"%d",maxee);   
     sprintf(m7,"%d",minee);
     lcd_gotoxy(5,1);       
     lcd_puts(m7); 
     lcd_gotoxy(0,1);
     lcd_puts(m6);    
       
 }
      
      
}
