# TODO
def main():
    text = input("Text: ")
    W = count_words(text)
    L = 100 * count_letters(text) / W
    S = 100 * count_sentences(text) / W
    index = round


if __name__ == "__main__":
    main()