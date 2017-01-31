import time
import serial

######
# This should be equal to DELAY on the firmware
delay_microseconds = 500000
######

ser = serial.Serial(
    port='/dev/ttyUSB0',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
    timeout=0)

raw_input("Press the reset button on the OpenMote, then press Enter to continue...")
i = 1

delay_seconds = float(delay_microseconds) / 1000000.0

while True:

    # Read the ADC value
    line = ser.readline()
    while len(line.split('@')) < 3:
        line = ser.readline()
    
    # Parse it
    value = int(line.split('@')[1])

    # Add to our vectors
    y.append(value)
    x.append(delay_seconds*i)
    
    print "ADC value: "+ str(value) + "\n"

    time.sleep(delay_seconds)
    i += 1
    
