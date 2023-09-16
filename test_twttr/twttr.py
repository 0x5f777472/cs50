def main():
    tweet = input("Input: ")
    print(shorten(tweet))


def shorten(word):
    mydict: {}
    for i in range(len(word)):
        if word[i].lower() in ["a", "e", "i", "o", "u"]:
            word.delete(word[i])
    return f"Output: {word}"

if __name__ == "__main__":
    main()
