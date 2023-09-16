tweet = input("Input: ")
print("Output: ", end = "")
for i in range(len(tweet)):
    if tweet[i].lower() not in ["a", "e", "i", "o", "u"]:
        print(tweet[i], end = "")
print()