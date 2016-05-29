#
# hello.temp.45.py
#
# receive and display temperature
# hello.temp.45.py serial_port
#
# Neil Gershenfeld
# CBA MIT 3/27/12
#
# (c) Massachusetts Institute of Technology 2012
# Permission granted for experimental and personal use;
# license for commercial sale available from MIT
#

from Tkinter import *
from numpy import log
import serial

WINDOW = 600 # window size
eps = 0.5 # filter time constant
filter = 0.0 # filtered value

def idle(parent,canvas):
   global filter, eps
   #
   # idle routine
   #
   byte2 = 0
   byte3 = 0
   byte4 = 0
   ser.flush()
   while 1:
      #
      # find framing 
      #
      byte1 = byte2
      byte2 = byte3
      byte3 = byte4
      byte4 = ord(ser.read())
      if ((byte1 == 1) & (byte2 == 2) & (byte3 == 3) & (byte4 == 4)):
         break
   low = ord(ser.read())
   high = ord(ser.read())
   value = 256*high + low
   if (value > 511):
      value -= 1024
   V = 2.5 - value*5.0/(20.0*512.0)
   R = 10000.0/(5.0/V-1.0)
   # NHQ103B375R5
   # R25 10000 (O)
   # B (25/85) 3750 (K)
   # R(T(C)) = R(25)*exp(B*(1/(T(C)+273.15)-(1/(25+273.15))))
   B = 3750.0
   R25 =  10000.0
   T = 1.0/(log(R/R25)/B+(1/(25.0+273.15))) - 273.15
   filter = (1-eps)*filter + eps*T
   x = int(.2*WINDOW + (.9-.2)*WINDOW*(filter-20.0)/10.0)
   canvas.itemconfigure("text",text="%.2f"%filter)
   canvas.coords('rect1',.2*WINDOW,.05*WINDOW,x,.2*WINDOW)
   canvas.coords('rect2',x,.05*WINDOW,.9*WINDOW,.2*WINDOW)
   canvas.update()
   parent.after_idle(idle,parent,canvas)

#
#  check command line arguments
#
if (len(sys.argv) != 3):
   print "command line: hello.temp.45.py serial_port"
   sys.exit()
port = sys.argv[1]
#
# open serial port
#
ser = serial.Serial(port,9600)
ser.setDTR()
#
# start plotting
#
root = Tk()
root.title('hello.temp.45.py (q to exit)')
root.bind('q','exit')
canvas = Canvas(root, width=WINDOW, height=.25*WINDOW, background='white')
canvas.create_text(.1*WINDOW,.125*WINDOW,text=".33",font=("Helvetica", 24),tags="text",fill="#0000b0")
canvas.create_rectangle(.2*WINDOW,.05*WINDOW,.3*WINDOW,.2*WINDOW, tags='rect1', fill='#b00000')
canvas.create_rectangle(.3*WINDOW,.05*WINDOW,.9*WINDOW,.2*WINDOW, tags='rect2', fill='#0000b0')
canvas.pack()
root.after(100,idle,root,canvas)
root.mainloop()
