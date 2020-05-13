#!/usr/bin/env python3
import wx
import wx.html
from xml.etree.ElementTree import parse
from urllib.request import urlopen

class ReadRSS(wx.Frame):
    def __init__(self, *args, **kw):
        super().__init__(*args, **kw)
        self.InitUI()
    
    def InitUI(self):
        pnl = wx.Panel(self)

        rssFile = urlopen("http://slashdot.org/slashdot.rss")
        xmlFile = parse(rssFile)

        self.dict = {}
        for item in xmlFile.findall('{http://purl.org/rss/1.0/}item'):
            title = item.findtext('{http://purl.org/rss/1.0/}title')
            description = item.findtext('{http://purl.org/rss/1.0/}description')
            front,mid,back = description.partition("<p>")
            self.dict[title] = front

        listbox = wx.ListBox(self, size=(400,400), pos=(20,50))
        for key in self.dict:
            listbox.Append(key)

        self.html = wx.html.HtmlWindow(self, size=(400,400),pos=(450,50))
        self.Bind(wx.EVT_LISTBOX, self.DisplayDesc)

        self.SetSize(900,500)
        self.SetTitle('RSS')
        self.Centre()
        self.Show(True)

    def DisplayDesc(self, event):
        titleString = event.GetString()
        self.html.SetPage(self.dict.get(titleString))

app = wx.App()
ReadRSS(None)
app.MainLoop()