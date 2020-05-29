#!/usr/bin/ env python3
import wx
import wx.html
from urllib.parse import quote
from urllib.request import urlopen
from PIL import Image

class IMDB_Movie_Search(wx.Frame):
    def __init__(self, *args, **kw):
        super().__init__(*args, **kw)
        self.InitUI()

    def InitUI(self):
        self.pnl = wx.Panel(self)
        self.PhotoMaxSize = 300,600
        self.bit = wx.StaticBitmap(self.pnl, pos=(300,100))
        self.urlTitle = "https://en.wikipedia.org/w/api.php?%20format=json&action=query&prop=extracts&exintro=&explaintext=&titles="
        self.urlImage = "https://en.wikipedia.org/w/api.php?action=query&format=json&prop=images&titles="
        self.urlImage1 = "https://en.wikipedia.org/w/api.php?%20action=query&list=allimages&format=json&aifrom="

        MovieTitleLabel = wx.StaticText(self.pnl, label="Movie title", pos=(20,20))
        self.EnterLabel = wx.TextCtrl(self.pnl, pos=(20,50), size=(230,30))
        self.buttonSearch = wx.Button(self.pnl, label="Search", size=(100,30), pos=(400,600))
        self.buttonClose = wx.Button(self.pnl, label="Close", size=(100,30), pos=(530,600))
        self.html = wx.html.HtmlWindow(self.pnl, size=(420,550),pos=(280,20))

        self.buttonClose.Bind(wx.EVT_BUTTON, self.OnClose)
        self.buttonSearch.Bind(wx.EVT_BUTTON, self.OnSearch)

        self.SetSize(1100,700)
        self.SetTitle('IMDB Movie Search')
        self.Centre()
        self.Show(True)

    def OnClose(self,event):
        self.Close()

    def OnSearch(self,event):
        self.txt = self.EnterLabel.GetValue()
        self.urlMovie = self.urlTitle + quote(self.txt)
        self.urlMovieImage = self.urlImage + quote(self.txt)
        self.DisplayText()
        self.DisplayImage()

    def DisplayText(self):
        openURL = urlopen(self.urlMovie)
        fileRead = openURL.read()

        description = fileRead.decode("utf-8")
        description = description.split("\"extract\":\"",1)
        description = description[1].split("\"}",1)
        description = description[0]
        self.html.SetPage(description)

    def DisplayImage(self):
        openURLImage = urlopen(self.urlMovieImage)
        fileImageRead = openURLImage.read()

        description1 = fileImageRead.decode("utf-8")
        description1 = description1.split("\"images\":[")
        description1 = description1[1].replace("{", '')
        description1 = description1.replace("}",'')

        split = self.txt.split(' ', 1)[0]
        if split in description1:
            description1 = description1.split(split)
            description1 = description1[1].split("\"", 1)
            s = split + str(description1[0])
        description1 = quote(s)

        self.urlImage2 = self.urlImage1 + description1
        print(self.urlImage2)

        openURLImage2 = urlopen(self.urlImage2)
        fileImageRead2 = openURLImage2.read()

        description2 = fileImageRead2.decode("utf-8")

        description2 = description2.split("url\":\"")
        description2 = description2[1].split(".jpg",1)
        description2 = description2[0] + ".jpg"
        print(description2)

        w = urlopen(description2)
        self.g = Image.open(w)
        self.ConvertToBitmap()


    def ConvertToBitmap(self):
        self.image = wx.Image(self.g.size[0],self.g.size[1])
        self.image.SetData(self.g.convert("RGB").tobytes())
        if self.image.HasAlpha():
            self.image.SetAlphaData(self.g.convert("RGBA").tobytes()[3::4])
    
        self.bitmapp = wx.Bitmap(self.image)
        
        self.bit.SetBitmap(self.bitmapp)

app = wx.App()
IMDB_Movie_Search(None)
app.MainLoop()