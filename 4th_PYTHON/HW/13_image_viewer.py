#!/usr/bin/env python
import wx
import os
from PIL import Image
from PIL import ImageFilter


class ImageViewer(wx.Frame):
    def __init__(self, *args, **kw):
        super().__init__(*args, **kw)
        self.InitUI()

    def InitUI(self):
        self.pnl = wx.Panel(self)
        self.PhotoMaxSize = 600,650
        self.check = False
        self.count = 0

        self.boxSizer = wx.BoxSizer(wx.HORIZONTAL)
        self.boxSizer.Add(self.pnl, flag=wx.EXPAND | wx.ALL)
        self.SetSizer(self.boxSizer)

        self.img=wx.StaticBitmap(self.pnl, pos=(20,20), size=(600,650))

        InfoLabel = wx.StaticText(self.pnl, label="Info" ,pos = (800, 50))
        NameLabel = wx.StaticText(self.pnl, label="Name: ", pos = (700,100))
        SizeLabel = wx.StaticText(self.pnl, label="Size: ", pos = (700,130))
        TypeLabel = wx.StaticText(self.pnl, label="Type: ", pos = (700,160))
        ColorLabel = wx.StaticText(self.pnl, label="Colors: ", pos = (700,190))
        self.Filename = wx.StaticText(self.pnl, pos=(750,100))
        self.Filesize = wx.StaticText(self.pnl, pos=(750,130))
        self.Filetype = wx.StaticText(self.pnl, pos=(750,160))
        self.Filecolor = wx.StaticText(self.pnl, pos=(750,190))

        self.buttonOpenFile = wx.Button(self.pnl, label="Open file", size=(100,30), pos=(200,700))
        self.buttonOpenFile.Bind(wx.EVT_BUTTON, self.OpenFile)

        self.buttonSaveFile = wx.Button(self.pnl, label="Save file", size=(100,30), pos=(350,700))
        self.buttonSaveFile.Bind(wx.EVT_BUTTON, self.SaveFile)

        OptionLabel = wx.StaticText(self.pnl, label="Options", pos = (800,250))

        self.buttonRotate = wx.Button(self.pnl, label="Rotate", size=(100,30), pos=(775,300))
        self.buttonRotate.Bind(wx.EVT_BUTTON, self.RotateImage)

        self.buttonFlipTop = wx.Button(self.pnl, label="Flip Top|Bottom", size=(150,30), pos=(755,360))
        self.buttonFlipTop.Bind(wx.EVT_BUTTON, self.FlipTopBottom)

        self.buttonFlipLeft = wx.Button(self.pnl, label="Flip Left|Right", size=(150,30), pos=(755,420))
        self.buttonFlipLeft.Bind(wx.EVT_BUTTON, self.FlipLeftRight)

        self.buttonFilter = wx.Button(self.pnl, label="Filter", size=(100,30), pos=(900,482))
        filters = ['BLUR', 'CONTOUR', 'DETAIL', 'EDGE_ENHANCE','EDGE_ENHANCE_MORE', 'EMBOSS', 'FIND_EDGES','SMOOTH', 'SMOOTH_MORE', 'SHARPEN']
        self.combo=wx.ComboBox(self.pnl,choices=filters, pos=(700, 480))
        self.buttonFilter.Bind(wx.EVT_BUTTON, self.Filter)

        self.buttonSize = wx.Button(self.pnl, label="Resize", size=(100,30), pos=(900,540))
        sizes = ['1920x1080', '1600x900', '1440x900', '1280x720', '1024x768', '800x600', '640x480']
        self.comboSize = wx.ComboBox(self.pnl, choices=sizes, pos=(700,540))
        self.buttonSize.Bind(wx.EVT_BUTTON, self.ResizeImage)

        self.SetSize(1050,800)
        self.SetTitle('Image Viewer')
        self.Centre()
        self.Show(True)

    def OpenFile(self,event):
        openFileDialog = wx.FileDialog(self, "Open", "", "", "Image files (*.png,*.jpeg,*.jpg)|*.png;*.jpeg;*.jpg", wx.FD_OPEN | wx.FD_FILE_MUST_EXIST)
        openFileDialog.ShowModal()
        self.pathname = openFileDialog.GetPath()
        try:
            self.pilImage = Image.open(self.pathname)
            self.originalSize = self.pilImage.size
            self.showImage()
        except IOError:
            wx.LogError("Cannot save current data in file '%s'." % self.pathname)
        self.ShowInfo()

    def ShowInfo(self):
        self.Filename.SetLabel(os.path.split(self.pathname)[-1])
        self.Filesize.SetLabel(str(self.originalSize[0]) + " x " +str(self.originalSize[1]) + " pixels")
        self.Filetype.SetLabel(self.pilImage.format + " image")
        colors = ''.join(self.pilImage.getbands())
        self.Filecolor.SetLabel(colors)

    def showImage(self):
        self.pilImage.thumbnail(self.PhotoMaxSize)
        self.ConvertToBitmap()

    def ConvertToBitmap(self):
        self.image = wx.Image(self.pilImage.size[0],self.pilImage.size[1])
        self.image.SetData(self.pilImage.convert("RGB").tobytes())
        if self.image.HasAlpha():
            self.image.SetAlphaData(self.pilImage.convert("RGBA").tobytes()[3::4])
    
        self.bitmapp = wx.Bitmap(self.image)
        
        self.img.SetBitmap(self.bitmapp)

    def RotateImage(self, event):
        self.count += 1
        self.pilImage = self.pilImage.rotate(90, expand=True)
        self.ConvertToBitmap()

    def FlipTopBottom(self, event):
        self.pilImage = self.pilImage.transpose(Image.FLIP_TOP_BOTTOM)
        self.ConvertToBitmap()

    def FlipLeftRight(self, event):
        self.pilImage = self.pilImage.transpose(Image.FLIP_LEFT_RIGHT)
        self.ConvertToBitmap()

    def Filter(self, event):
        val = self.combo.GetValue()
        self.pilImage = self.pilImage.filter(getattr(ImageFilter, val))
        self.ConvertToBitmap()

    def ResizeImage(self, event):
        self.val = self.comboSize.GetValue()
        self.check = True
        self.Filesize.SetLabel(self.val)
        
    def SaveFile(self, event):
        if self.check == False:
            if self.count%2 == 0:
                self.pilImage = self.pilImage.resize(self.originalSize)
            else:
                self.pilImage = self.pilImage.resize((self.originalSize[1],self.originalSize[0]))
        else:
            self.pilImage = self.pilImage.resize(tuple(map(int, self.val.split('x'))) )
            
        self.pilImage.save(os.path.split(self.pathname)[-1])
        self.showImage()



app = wx.App()
ImageViewer(None)
app.MainLoop()