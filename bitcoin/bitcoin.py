import requests
import sys

try:
    if len(sys.argv) == 2:
        multiplier = float(sys.argv[1])
        price = requests.get('https://api.coindesk.com/v1/bpi/currentprice.json').json()["bpi"]["USD"]["rate_float"]
        print(f"${(price * multiplier):,.4f}")
    elif len(sys.argv) == 1:
        print("Missing command-line argument")
        sys.exit(1)
except requests.RequestException:
    print("could not fetch a the data :-(")
    sys.exit(2)
except ValueError:
    print("Command-line argument is not a number")
    sys.exit(3)