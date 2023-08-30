# TODO
def main():
    text = input("Text: ")
    W = count_words(text)
    L = 100 * count_letters(text) / W
    S = 100 * count_sentences(text) / W
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(text):
    count = 0
    for letter in text:
        if letter.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for letter in text:
        if letter.isspace():
            count += 1
    return count


def count_sentences(text):
    count = 0
    for letter in text:
        if letter == "." or letter == "!" or letter == "?":
            count += 1


if __name__ == "__main__":
    main()
