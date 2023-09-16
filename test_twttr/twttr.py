def main():
    tweet = input("Input: ")
    print(shorten(tweet))


def shorten(word):
    no_vowels = str.maketrans("aeiouAEIOU", None)
    return f"Output: {word.translate(no_vowels)}"
if __name__ == "__main__":
    main()
