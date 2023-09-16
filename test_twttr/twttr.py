def main():
    tweet = input("Input: ")
    print(shorten(tweet))


def shorten(word):
    for i in range(len(word)):
        if word[i].lower() not in ["a", "e", "i", "o", "u"]:
            print(word[i], end = "")
    return f"Output: {}"

if __name__ == "__main__":
    main()
