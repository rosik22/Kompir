#!/usr/bin/env python3

import pyinputplus as pyip

while True:
    message = "Do you want to know how to keep an idiot busy?\n"
    response = pyip.inputYesNo(message)
    if response == 'no':
        print("Thank you. Have a nice day")
        break