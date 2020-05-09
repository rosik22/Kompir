#!/usr/bin/env python3
import sqlite3
from sys import argv

query = str(argv[1])

conn = sqlite3.connect('f91298-food.db')
curs = conn.cursor()
curs.execute('''CREATE TABLE IF NOT EXISTS food 
            (code TEXT, descript TEXT, nmbr INTEGER, nutname TEXT, retention INTEGER, UNIQUE(descript,nmbr))''')
conn.commit()

retnFile = open("retn5_dat1.txt", 'r')
content = retnFile.read()
rows = content.split('\n')

formatted = [list(x.replace('~','').split('^')) for x in rows]

for i in formatted:
    curs.execute('''REPLACE INTO food(code,descript,nmbr,nutname,retention) 
                    VALUES(?,?,?,?,?)''', (i[0],i[1],i[2],i[3],i[4]))

conn.commit()

curs.execute(query)
row = curs.fetchone()
if(row!=None):
    print(list(row))