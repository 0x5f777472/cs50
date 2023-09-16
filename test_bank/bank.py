def main():
    greeting = input("Greeting: ")
    print(f"${value(greeting)}")


def value(greeting):
    if greeting.strip()[:5].lower() == "hello":
        return 0
    elif greeting[0].lower() == "h":
        return 20
    else:
        return 100


if __name__ == "__main__":
    main()
