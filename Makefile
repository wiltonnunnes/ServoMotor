hex:
	avr-g++ -Os -DF_CPU=16000000 -mmcu=atmega328p -c main.cpp
	avr-g++ -DF_CPU=16000000 -mmcu=atmega328p -o main.elf main.o
	avr-objcopy -O ihex main.elf main.hex
	rm main.o
	rm main.elf

flash:
	avrdude -c arduino -p m328p -P /dev/ttyACM0 -U flash:w:main.hex

clear:
	rm main.hex