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
    else
        print(f"Grade {index}")

def count_letters(text):
    
if __name__ == "__main__":
    main()