def main():
    tweet = input("Input: ")
    print(shorten(tweet))


def shorten(word):
    mydict= {65:None,69:None,73:None,79:None,85:None,97:None,101:None,105:None,111:None,117:None}
    return f"Output: {word.translate(mydict)}"
if __name__ == "__main__":
    main()
