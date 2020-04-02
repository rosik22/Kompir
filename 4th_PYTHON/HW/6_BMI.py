#!/usr/bin/env python3
import wx

class BMI(wx.Frame):
    def __init__(self, *args, **kw):
        super(BMI,self).__init__(*args,**kw)
        self.InitUI()

    def InitUI(self):
        pnl = wx.Panel(self)
        heading = wx.StaticText(pnl, label='Body Mass Index', pos=(30, 30))
        
        self.weight = wx.StaticText(pnl, label='weight:', pos = (30,110))
        self.wv = wx.SpinCtrl(pnl, value='0', pos=(150, 110), size=(60, -1))
        self.wv.SetRange(0, 300)

        self.SetSize(350,350)
        self.SetTitle('wx.SpinCtrl')
        self.Centre()
        self.Show(True)

def main():
    app = wx.App()
    BMI(None)
    app.MainLoop()

if __name__ == '__main__':
    main()
