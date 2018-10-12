/*
 * CFile1.c
 *
 * Created: 3/21/2018 6:31:07 PM
 *  Author: Vlad
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void init_ADC()
{
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //div cu 128 => 125 kHz
	ADMUX |=(1<<REFS0); //RESF0=0 => AVCC with external capacitor at AREF pin; 0b0100 0000
	ADCSRA |=1<<ADIE; // intrerupere enable
	ADCSRA |=1<<ADEN;  // ADC enable
	
	sei(); //intrerupere globala enable
	ADCSRA |=1<<ADSC;  //start conversie
	
}

