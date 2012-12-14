/*
 * SinusoidOscillator.cpp
 *
 * Created: 9/15/2012 10:01:12 PM
 *  Author: John
 */ 

#include <math.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int TABLE_SIZE = 256;
volatile int index = 0;
volatile unsigned char * wavetable;


ISR( TIMER1_COMPA_vect );
void init( void );
void setupTable( void );

int main( void )
{
	init();
    while( 1 )
    {
        //TODO:: Please write your application code 
    }

	//free( wavetable );
}

ISR( TIMER1_COMPA_vect ) {
	PORTD = wavetable[index];
	if( index < TABLE_SIZE - 1 ) {
		++index;
	} else {
		index = 0;
	}
}

void init( void ) {
	cli();
	DDRD |= 0xFF;
	PORTD &= 0x0;
	TCCR1B &= 0x0;
	
	OCR1A = 283;	// 16 MHz clock / 220 Hz frequency / 256 samples / 1 prescaler
	TCCR1B |= ( 1 << CS10 | 1 << WGM12 ); // 1 prescaler
	TIMSK1 |= ( 1 << OCIE1A );
	setupTable();
	sei();
}

void setupTable( void ) {
	wavetable = ( volatile unsigned char* ) malloc( TABLE_SIZE * sizeof( volatile unsigned char ) );
	float phaseIncrement = ( 2.0f * M_PI ) / 256.0f; // 256 samples in the table
	float currentPhase = 0.0f;

	for( volatile int i = 0; i < TABLE_SIZE; i++ ) {
		wavetable[i] = (unsigned char) ( ( 127.0f * sin( currentPhase ) ) + 127.0f );
		currentPhase += phaseIncrement;
	}
}