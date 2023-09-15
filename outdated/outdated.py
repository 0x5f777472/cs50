months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
date = input("Date: ")
try:
    month, day, year = date.split("/")
    print(month,day,year)
except:
    month, day, year = date.split(" ")
    day = day.rstrip(",")
    month = months.index[month] + 1
    print(month,day,year)