import sys
from pyfiglet import Figlet
word = input("Input: ")
print("Output:\n" + Figlet(font=sys.argv[2]).renderText(word))