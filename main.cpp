#include <avr/io.h>

void setup_timer1();

int main(void)
{
    DDRB |= (1 << PB1);
    setup_timer1();
    while(1){
        OCR1A = 1999;
        while((TIFR1 & 1) == 0);
        TIFR1 |= 1;
        OCR1A = 2999;
        while((TIFR1 & 1) == 0);
        TIFR1 |= 1;
    }

    return 0;
}

void setup_timer1() {
    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    ICR1 = 39999;
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11);
}
