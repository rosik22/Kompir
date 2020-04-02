#!/usr/bin/env python3
import wx


class Example(wx.Frame):
    def __init__(self, *args, **kw):
        super(Example, self).__init__(*args, **kw)
        self.InitUI()

    def InitUI(self):
        self.pizza = 'pepperoni-pizza'
        self.bitmap = wx.Bitmap('pepperoni-pizza-small.jpg', wx.BITMAP_TYPE_JPEG)
        pnl = wx.Panel(self)
        font = wx.Font(10, wx.DEFAULT, wx.NORMAL, wx.BOLD)
        heading = wx.StaticText(pnl, label='Pizza Menu', pos=(105, 10))
        heading.SetFont(font)
        self.rb1 = wx.RadioButton(pnl, label='Pepperoni', pos=(15, 60), style=wx.RB_GROUP)
        self.rb2 = wx.RadioButton(pnl, label='Veggie', pos=(15, 85))
        self.rb3 = wx.RadioButton(pnl, label='Margherita', pos=(15, 110))
        self.rb4 = wx.RadioButton(pnl, label='Prosciutto e Funghi', pos=(15, 135))
        
        wx.StaticLine(pnl, pos=(55, 35), size=(200, 1))
        wx.StaticBox(pnl, label='Additional', pos=(180, 40), size=(190, 120))
        self.check1 = wx.CheckBox(pnl, label='hot peppers', pos=(180, 60))
        self.check2 = wx.CheckBox(pnl, label='cheese', pos=(180, 85))
        
        self.quantity = wx.StaticText(pnl, label='Quantity', pos=(15, 180))
        
        btn = wx.Button(pnl, label='Ok', pos=(90, 355), size=(60, -1))
        btn.Bind(wx.EVT_BUTTON, self.OnOrder)
        
        self.sc = wx.SpinCtrl(pnl, value='0', pos=(90, 175), size=(60, -1))
        self.sc.SetRange(0, 20)
        self.img = wx.StaticBitmap(pnl, 0, self.bitmap, pos=(15, 210))
        self.rb1.Bind(wx.EVT_RADIOBUTTON,self.SetVal, id=self.rb1.GetId())
        self.rb2.Bind(wx.EVT_RADIOBUTTON,self.SetVal, id=self.rb2.GetId())
        self.rb3.Bind(wx.EVT_RADIOBUTTON,self.SetVal, id=self.rb3.GetId())
        self.rb4.Bind(wx.EVT_RADIOBUTTON,self.SetVal, id=self.rb4.GetId())
        
        self.SetSize((400, 450))
        self.SetTitle('Offline pizza selector')
        self.Centre()
        self.Show(True)

    def OnOrder(self, e):
        s = ''
        print(self.check1.GetValue())
        if self.check1.GetValue():
            s += 'with hot peppers'
        if self.check2.GetValue():
            s += 'with cheese'
        print(self.sc.GetValue(), self.pizza, s)

    def SetVal(self, e):
        eid = e.GetId()
        if eid == self.rb1.GetId():
            self.bitmap.LoadFile(
                'pepperoni-pizza-small.jpg', wx.BITMAP_TYPE_JPEG)
            self.img.SetBitmap(self.bitmap)
            self.pizza = 'Pepperoni pizza'
        elif eid == self.rb2.GetId():
            self.bitmap.LoadFile('veggie-pizza-small.jpg',wx.BITMAP_TYPE_JPEG)
            self.img.SetBitmap(self.bitmap)
            self.pizza = 'Veggie pizza'
        elif eid == self.rb3.GetId():
            self.bitmap.LoadFile('margherita-pizza-small.jpg',wx.BITMAP_TYPE_JPEG)
            self.img.SetBitmap(self.bitmap)
            self.pizza = 'Margherita pizza'
        elif eid==self.rb4.GetId():
            self.bitmap.LoadFile('pizza-prosciutto-e-funghi-small.jpg',wx.BITMAP_TYPE_JPEG)
            self.img.SetBitmap(self.bitmap)
            self.pizza= 'Pizza prosciutto e funghi pizza'

def main():
    ex = wx.App()
    Example(None)
    ex.MainLoop()

if __name__ == '__main__':
    main()
