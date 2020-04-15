#!/usr/bin/env python3

class Fibs:
    def __init__(self):
        self.n1 = 0
        self.n2 = 1

    def __next__(self):
        temp = self.n1 + self.n2
        self.n1 = self.n2
        self.n2 = temp
        return self.n2

    def __iter__(self):
        return self

fibs = Fibs()
for f in fibs:
   if f > 1000:
      print(f)
      break