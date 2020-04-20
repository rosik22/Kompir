#!/usr/bin/env python3
import pyinputplus as pyip
import random, time

numQuestions = 10
correctAnswers = 0

for questionNum in range(numQuestions):
    num1 = random.randint(0,9)
    num2 = random.randint(0,9)
    prompt = '#%s: %s x %s =' %(questionNum,num1,num2)

    try:
        pyip.inputStr(prompt, allowRegexes=['^%s$'%(num1*num2)],
                    blockRegexes=[('.*','Incorrect')],
                    timeout=10, limit=3)

    except pyip.TimeoutException:
        print("Out of time!")
    except pyip.RetryLimitException:
        print("Out of tries!")
    else:
        print("Correct!")
        correctAnswers += 1
    time.sleep(1)

print("Score: %s / %s" %(correctAnswers,numQuestions))