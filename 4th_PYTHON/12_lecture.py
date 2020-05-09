#!/usr/bin/env python
# -*- coding: utf-8 -*-
from urllib.request import urlopen

website = urlopen('https://www.sinoptik.bg/sofia-bulgaria-100727011?location')
for l in website:
    line = l.decode()
    if '<meta property="og:description" content=' in line:
        lf = line.find('Времето')
        rg = line.find('Подробна')
        weather = line[lf:rg]
        print(weather)
        break
