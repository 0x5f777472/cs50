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
while True:
    date = input("Date: ")iiiiiiiiio
    try:
        if date.split("/")[0].isnumeric():
            month, day, year = date.split("/")
            month, day, year = int(month), int(day), int(year)
            if month - 1 in range(12) and day - 1 in range(31):
                print(f"{year:02}-{month:02}-{day:02}")
                break

        else:
            month, day, year = date.split(" ")
            day = day.rstrip(",")
            month = months.index(month) + 1
            month, day, year = int(month), int(day), int(year)
            if month - 1 in range(12) and day - 1 in range(31):
                print(f"{year:02}-{month:02}-{day:02}")
                break
    except:
        continue