import time
import os
import serial
import matplotlib.pyplot as plt

######
# This should be equal to DELAY on the firmware
delay_microseconds = 500000
######

# Open the serial port
ser = serial.Serial(
    port='/dev/ttyUSB0',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
    timeout=0)

if os.path.isfile("./output.txt"):
    os.remove("output.txt")

raw_input("Press the reset button on the OpenMote, then press Enter to continue...")

delay_seconds = float(delay_microseconds) / 1000000.0
while True:

    # Read the ADC value from OpenMote
    line = ser.readline()
    while len(line.split('@')) < 3:
        line = ser.readline()
    
    # Parse it
    try:
        value = int(line.split('@')[1])
        # Write to the file
        file = open("output.txt",'a')
        file.write(str(value) + "\n")    
        print "ADC value: "+ str(value)
        file.close()

    except:
        print "Error while reading."

    # Sleep for some time
    time.sleep(delay_seconds)
    
