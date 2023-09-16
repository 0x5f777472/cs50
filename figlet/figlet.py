import sys
from pyfiglet import Figlet
f = Figlet(font='slant')
print(f.renderText(sys.argv[1]))