from fpdf import FPDF

class shirtificate(FPDF):
    def __init__(self, name):
        super().__init__()
        self.name = name
    def ...():
        ...


def main():
    name = input("Name: ").strip() + " took CS50"
    shirtificate(name).example

if __name__ == "__main__":
    main()