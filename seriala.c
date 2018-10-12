/*
 * seriala.c
 *
 * Created: 3/21/2018 4:25:34 PM
 *  Author: Vlad
 */ 
#include "seriala.h"
#include <avr/io.h> 
#include <avr/interrupt.h>
void USART_Init( unsigned int registru)
{
	/*Setare registru baud rate*/
	/* UBRR0H este [3:0] astfel incat primii 4 biti sunt incarcati iar restul sunt incarcati
	in UBRR0L
	*/  
	UBRR0H = (unsigned char)(registru>>8);
	UBRR0L = (unsigned char)registru;
	

	/*transmitere ON */
	UCSR0B = (1<<TXEN0);
	
	/* Formatul frame-ului*/
	
	/*		USBS0=1 => 2 stop bits;
			UCSZ00=11 => data=8bits;
	 */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit( unsigned char data )
{
	/* astepta pana bufferul se goleste */
	/* UCSR0A devine 1 atunci cand datele UDR0 sunt transmise
	   UDR0 flag=1 =>> date transmise while(!(1&1)) => while(0);
	   UDR0 flag=0 =>> date netransmise while(!(0&1)) => while(1);
	  */
	
	while ( !( UCSR0A & (1<<UDRE0)) );
	
	/* UDR0-registru de date */
	UDR0 = data;
}

void USART_Transmit2( int data1 )
{
	/* astepta pana bufferul se goleste */
	/* UCSR0A devine 1 atunci cand datele UDR0 sunt transmise
	   UDR0 flag=1 =>> date transmise while(!(1&1)) => while(0);
	   UDR0 flag=0 =>> date netransmise while(!(0&1)) => while(1);
	  */
	
	while ( !( UCSR0A & (1<<UDRE0)) );
	
	/* UDR0-registru de date */
	UDR0 = data1;
}