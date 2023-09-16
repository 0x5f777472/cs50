import sys
from pyfiglet import Figlet
print(Figlet(font=sys.argv[2]).renderText(input("Input: ")))