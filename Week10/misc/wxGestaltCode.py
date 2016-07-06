
# Import main wxPython libraries
import wx
import wx.xrc
# Import the wxGestalt module for Gestalt Machines
import Machines.wxMachines as wxMachines


###########################################################################
## Class wxGestaltPanel
###########################################################################

class wxGestaltPanel(wx.Panel):
    &#39;&#39;&#39;
    This is the main class for the app that will be launched in the fifth tab.
    Do not rename the class, or wxGestalt won&#39;t open it in the tab.
    Please remember: if you print anything, it will go out to the second tab
    (2. Identify the nodes). So please add a text widget and update its value
    in order to show some text / values in the GUI.
    &#39;&#39;&#39;

    def __init__( self, parent ):
        &#39;&#39;&#39;
        This function initialize the interface. Add all your GUI elements here.
        The self.myMachine object is the machine you initialized in the first two tabs.
        Don&#39;t change it or it won&#39;t work. The self.launch_button will launch your
        code, change only its position.
        &#39;&#39;&#39;
        # Initialize the panel that contains all the GUI elements
        # Don&#39;t change this!
        wx.Panel.__init__ ( self, parent, id = wx.ID_ANY,
        pos = wx.DefaultPosition, size = wx.Size( 500,300 ),
        style = wx.TAB_TRAVERSAL )

        # Load the machine edited in the main app.
        # Don&#39;t change this!
        self.myMachine = self.GetParent().myMachine

        # Create sizers for organizing the GUI elements here
        self.mainSizer = wx.BoxSizer( wx.VERTICAL )
        # ...

        # Create GUI elements here
        txt1 = &quot;Just a text element to show you how to create GUI widgets...&quot;
        st1 = wx.StaticText(self, label=txt1, style=wx.ALIGN_CENTRE)
        # ...

        # Add GUI elements to the sizer here
        self.mainSizer.Add(st1, flag=wx.ALL, border=5)
        # ...

        # Bind events to GUI widgets here
        # ...

        # Add a button for launching your app.
        # You should only change the position of this!
        self.launch_button = wx.Button( self, wx.ID_ANY, u&quot;Run&quot;, wx.DefaultPosition, wx.DefaultSize, 0 )
        self.mainSizer.Add( self.launch_button, 0, wx.ALL, 5 )
        self.launch_button.Bind( wx.EVT_BUTTON, self.On_Run )

        # Set up sizers and layout
        # Don&#39;t change this!
        self.SetSizer( self.mainSizer )
        self.Layout()

    def On_CalculateMoves(self):
        &#39;&#39;&#39;
        Add here the function for calculating the move instructions to be sent to the machine.
        &#39;&#39;&#39;

        # Add here your algorithm
        # ...

        # Store here the final moves from your algorithm
        # The code below is just an example on how to structure the moves
        # according to the number of nodes
        if self.myMachine.nodesNumber == 1:
            moves = [[10],[20],[10],[0]]
        elif self.myMachine.nodesNumber == 2:
            moves = [[10,10],[20,20],[10,10],[0,0]]
        elif self.myMachine.nodesNumber == 3:
            moves = [[145,145,0],[40,40,0],[40,40,30],[145,145,30],[0,0,0]]
        elif self.myMachine.nodesNumber == 4:
            moves = [[10,10,10,10],[20,20,20,20],[10,10,10,10],[0,0,0,0]]

        # Return the value
        return moves

    def On_Run(self, event):
        &#39;&#39;&#39;
        This function will finally control the machine after you press the &quot;Run&quot; button.
        Do not change this function.
        &#39;&#39;&#39;
        # This will calculate the moves for your machine
        moves = self.On_CalculateMoves()
        # This will send the moves to the machine
        self.myMachine.moveMachine(moves)


