#!/usr/bin/env python3
import wx

class Example(wx.Frame):
    def __init__(self, *args, **kw):
        super(Example, self).__init__(*args, **kw)
        self.InitUI()
    
    def OnClose(self, e):
        self.Close(True)

    def InitUI(self):
        pnl = wx.Panel(self)
        cbnt = wx.Button(pnl, label='Close', pos=(20, 30))
        cbnt.Bind(wx.EVT_BUTTON, self.OnClose)
        self.SetSize((300, 300))
        self.SetTitle('wx.Button')
        self.Centre()
        self.Show(True)

        wx.StaticBox(pnl, pos=(95,135), size=(110,120))
        
        light = wx.ToggleButton(pnl, label = 'red', pos=(20,80))
        self.cpnl = wx.Panel(pnl, pos=(100,150), size = (100,100))
        light.Bind(wx.EVT_TOGGLEBUTTON, self.ToggleLight)


    def ToggleLight(self,e):
        obj = e.GetEventObject()
        isPressed = obj.GetValue()
        if isPressed:
            self.cpnl.SetBackgroundColour((128,0,0))
        else:
            self.cpnl.SetBackgroundColour((255,255,255))

def main():
    app = wx.App()
    Example(None)
    app.MainLoop()

if __name__ == '__main__':
    main()