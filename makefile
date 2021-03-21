a.hex: a.out
	avr-objcopy -O ihex -j .text -j .data a.out a.hex

a.out: src/main.c
	avr-gcc -Os -mmcu=attiny13 src/main.c

clean:
	rm *.out *.hex

upload: a.hex
	avrdude -p t13 -c stk500v1 -P /dev/ttyACM0 -b 19200 -U flash:w:a.hex:i