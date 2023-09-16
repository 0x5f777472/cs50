def main():
    tweet = input("Input: ")
    print(shorten(tweet))


def shorten(word):
    no_vowels = str.maketrans("","", "AEIOUaeiou")
    return f"Output: {word.translate(no_vowels)}"
if __name__ == "__main__":
    main()
