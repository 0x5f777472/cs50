def main():
    tweet = input("Input: ")
    print("Output: ", end="")
    print(shorten(tweet))


def shorten(word):
    no_vowels = str.maketrans("","", "AEIOUaeiou")
    return word.translate(no_vowels)
if __name__ == "__main__":
    main()
