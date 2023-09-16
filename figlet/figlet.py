import sys
from pyfiglet import Figlet
word = input("Input: ")
if len(sys.argv) == 1:
    print("Output:\n" + Figlet(font=random).renderText(word))

print("Output:\n" + Figlet(font=sys.argv[2]).renderText(word))