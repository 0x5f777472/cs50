def main():
    time_value = convert(input("What time is it? "))
    if 7 <= time_value <= 8:
        print("breakfast time")
    elif 12 <= time_value <= 13:
        print("lunch time")
    elif 18 <= time_value <= 19:
        print("dinner time")


def convert(time):
    time_list = time.split(":")
    hour = int(time_list[0])
    minutes = float(time_list[1])
    return hour + minutes / 60



if __name__ == "__main__":
    main()
