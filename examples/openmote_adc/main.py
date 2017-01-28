import time
import serial
import matplotlib.pyplot as plt

# Set the DELAY in microseconds
DELAY = 1000000

ser = serial.Serial(
    port='\dev\ttyUSB0',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
    timeout=0)

x = []
y = []    

raw_input("Reset the OpenMote, then press Enter to continue...")
i = 1
delay_seconds = (float)DELAY/1000000.0
while True:
    print "Running!\n"
	
	# Read the ADC value
    line = ser.readline()
	
	# Parse it
	value = int(line.split('@')[1])

	y.append(value)
	x.append(delay_seconds*i)
	
    print str(value) + '\n'
    time.sleep(delay_seconds)
	
	i += 1
	