
import json
from sys import stdin
from pprint import pprint

file = open("questionsAnswers.txt", "w", encoding="utf-8")
i = 0
with open('C:/Users/leeni/Documents/Code Stuff/Python Scripts/gameshow/jq.json') as f:
    data = json.load(f)
    for line in data:
        if line == '':
            break
        file.write("Question: " + data[i]['question'].strip("'") + "\n" + "Answer: " + data[i]['answer'].strip("'") + "\n")
        i+= 1

file.close()
