greet = input("Greeting: ")
if greet.strip()[:5].lower() == "hello":
    print("$0")
elif greet[0].lower() == "h":
    print("$20")
else:
    print("$100")