def main():
    tweet = input("Input: ")
    print(shorten(tweet))


def shorten(word):
    mydict= {97:None,101:None,105:None,111:None,117:None}
    return f"Output: {word.translate(mydict)}"

if __name__ == "__main__":
    main()
