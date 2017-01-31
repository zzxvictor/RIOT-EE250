import os
from bokeh.plotting import figure, curdoc
from bokeh.driving import linear

######
# This should be equal to DELAY on the firmware
delay_microseconds = 500000
######

file = open("output.txt", 'r')
delay_miliseconds = float(delay_microseconds) / 1000.0
i = 0

p = figure(plot_width=400, plot_height=400)
r1 = p.line([], [], color="firebrick", line_width=2)
ds1 = r1.data_source

@linear()
def update(step):
    
    # Read the value from the file
    line = file.readline()
    value = int(line)

    # Add to our vectors
    ds1.data['x'].append(step)
    ds1.data['y'].append(value)
    ds1.trigger('data', ds1.data, ds1.data)

curdoc().add_root(p)
curdoc().add_periodic_callback(update, delay_miliseconds)

