def main():
    tweet = input("Input: ")
    print("Output: ", end = "")
    shorten(tweet)


def shorten(word):
    for i in range(len(word)):
        if word[i].lower() not in ["a", "e", "i", "o", "u"]:
            print(word[i], end = "")
    print()

if __name__ == "__main__":
    main()
