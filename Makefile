TARGET = main
INCS = uart.c adc.c
compile:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p $(TARGET).c $(INCS) -o $(TARGET)
	avr-objcopy $(TARGET) -O ihex -R .eeprom $(TARGET).hex

upload:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$(TARGET).hex

clean:
	rm $(TARGET) *.hex
