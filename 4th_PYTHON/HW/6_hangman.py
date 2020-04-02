#! python
import wx
import random

class Hangman(wx.Frame):
    def __init__(self, *args, **kw):
        super(Hangman,self).__init__(*args, **kw)
        self.InitUI()

    def InitUI(self):
        pnl = wx.Panel(self)
        words = ["COMPUTER", "GUITAR","CALCULUS","ENGINE","BLENDER","DRAWING","ALGORITHM","SHOWER","BACKPACK"]
        self.currword = random.choice(words)
        self.counter = 0
        self.counter1 = 0
        self.letters = []
        self.DisplayFirstLast()
        self.DisplayDrawing()

        w = 30
        h=110
        for i in range(ord('A'), ord('Z')+1):
            self.button = wx.ToggleButton(self, 1005,label=chr(i),size =(30,30), pos = (w,h))
            if(w < 375):
                w += 35
            else:
                w = 30
                h += 35
        
        self.Bind(wx.EVT_TOGGLEBUTTON, self.OnButton, id=1005)

        gbtn = wx.Button(self, label="Guess", pos = (200,500))
        gbtn.Bind(wx.EVT_BUTTON, self.DisplayWord)
        
        self.SetSize(500,600)
        self.SetTitle('Hangman')
        self.Centre()
        self.Show(True)


    def DisplayFirstLast(self):
        k = wx.ClientDC(self)
        leng = len(self.currword)
        wx.StaticText(self, label = self.currword[0], pos=(180,40))
        wx.StaticText(self, label = self.currword[-1], pos=(165+leng*15,40))
        w = 195
        for i in self.currword[1:-1]:
            wx.StaticText(self, label = "_", pos=(w,40))
            w += 15
        
    def DisplayWord(self,e):
        cc = wx.ClientDC(self)
        check = ''.join(self.letters[-1:])
        word = self.currword[1:-1]
        w = 195

        if self.counter < 6:
            if check not in word:
                self.counter += 1
                self.DisplayDrawing()
            
            for letter in word: 
                if check == letter:
                    self.counter1 += 1
                    wx.StaticText(self, label = letter, pos=(w,40))
                w += 15
        if self.counter1 == len(word):
            wx.StaticText(self, label ="YOU ESCAPED DEATH!!!", pos=(175,80))

    def DisplayDrawing(self):
        if self.counter == 0:
            png = wx.Image("Hangman-0.png", wx.BITMAP_TYPE_PNG).ConvertToBitmap()
            wx.StaticBitmap(self, -1, png, (50, 220), (png.GetWidth(), png.GetHeight()))
            wx.StaticText(self, label ="You have " + str(6 - self.counter) + " tries left", pos=(175,80))
        if self.counter == 1:
            png = wx.Image("Hangman-1.png", wx.BITMAP_TYPE_PNG).ConvertToBitmap()
            wx.StaticBitmap(self, -1, png, (50, 220), (png.GetWidth(), png.GetHeight()))
            wx.StaticText(self, label ="You have " + str(6 -self.counter) + " tries left", pos=(175,80))
        elif self.counter == 2:
            png = wx.Image("Hangman-2.png", wx.BITMAP_TYPE_PNG).ConvertToBitmap()
            wx.StaticBitmap(self, -1, png, (50, 220), (png.GetWidth(), png.GetHeight()))
            wx.StaticText(self, label ="You have " + str(6 -self.counter) + " tries left", pos=(175,80))
        elif self.counter == 3:
            png = wx.Image("Hangman-3.png", wx.BITMAP_TYPE_PNG).ConvertToBitmap()
            wx.StaticBitmap(self, -1, png, (50, 220), (png.GetWidth(), png.GetHeight()))
            wx.StaticText(self, label ="You have " + str(6 -self.counter) + " tries left", pos=(175,80))
        elif self.counter == 4:
            png = wx.Image("Hangman-4.png", wx.BITMAP_TYPE_PNG).ConvertToBitmap()
            wx.StaticBitmap(self, -1, png, (50, 220), (png.GetWidth(), png.GetHeight()))
            wx.StaticText(self, label ="You have " + str(6 -self.counter) + " tries left", pos=(175,80))
        elif self.counter == 5:
            png = wx.Image("Hangman-5.png", wx.BITMAP_TYPE_PNG).ConvertToBitmap()
            wx.StaticBitmap(self, -1, png, (50, 220), (png.GetWidth(), png.GetHeight()))
            wx.StaticText(self, label ="You have " + str(6 -self.counter) + " tries left", pos=(175,80))
        elif self.counter == 6:
            png = wx.Image("Hangman-6.png", wx.BITMAP_TYPE_PNG).ConvertToBitmap()
            wx.StaticBitmap(self, -1, png, (50, 220), (png.GetWidth(), png.GetHeight()))
            wx.StaticText(self, label ="YOU HAVE BEEN EXECUTED", pos=(175,80))

    def OnButton(self,event):
        blabel = event.GetEventObject()
        self.letters.append(blabel.GetLabelText())

app = wx.App()
Hangman(None)
app.MainLoop()