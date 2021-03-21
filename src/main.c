#define DDRB (*(volatile unsigned char*) 0x37)
#define PORTB (*(volatile unsigned char*) 0x38)


void delay(volatile long time) {
    while (time > 0)
        time--;
}

int main() {
    // Set pin PB4 as OUTPUT
    DDRB |= (1 << 4);

    while (1) {
        // Toggle PB4
        PORTB ^= (1 << 4);
        delay(10000);
    }
}