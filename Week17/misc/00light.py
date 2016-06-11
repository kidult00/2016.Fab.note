#
# hello.light.45.py
#
# receive and display light level
# hello.light.45.py serial_port
#
# week 16 assignment by 00

from Tkinter import *
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
   filter = (1-eps)*filter + eps*value
   x = int(.2*WINDOW + (.9-.2)*WINDOW*filter/1024.0)
   canvas.itemconfigure("text",text="%.1f"%filter)
   canvas.coords('rect1',.2*WINDOW,.05*WINDOW,x,.2*WINDOW)
   canvas.coords('rect2',x,.05*WINDOW,.9*WINDOW,.2*WINDOW)
   canvas.update()
   parent.after_idle(idle,parent,canvas)

#
#  check command line arguments
#
if (len(sys.argv) != 3):
   print "command line: hello.light.45.py serial_port"
   sys.exit()
port = sys.argv[1]
#
# open serial port
#
ser = serial.Serial(port,9600)
ser.setDTR()
#
# set up GUI
#
root = Tk()
root.title('light sensor test by 00 (q to exit)')
root.bind('q','exit')
canvas = Canvas(root, width=WINDOW, height=.5*WINDOW, background='white')
canvas.create_text(.1*WINDOW,.125*WINDOW,text=".33",font=("Helvetica", 24),tags="text",fill="#0000b0")
canvas.create_rectangle(.2*WINDOW,.05*WINDOW,.3*WINDOW,.2*WINDOW, tags='rect1', fill='#F8E71C')
canvas.create_rectangle(.3*WINDOW,.05*WINDOW,.9*WINDOW,.2*WINDOW, tags='rect2', fill='#F5A623')
canvas.pack()
#
# start idle loop
#
root.after(100,idle,root,canvas)
root.mainloop()
