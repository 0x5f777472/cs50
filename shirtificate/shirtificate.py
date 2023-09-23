from fpdf import FPDF

class shirtificate(FPDF):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def generate_picture(self):
        self.add_page()
        self.image("shirtificate.png", 10, 70, 190)
        self.set_font("courier", size=48)
        self.cell(0, 55, "CS50 Shirtificate!", align="C")
        self.ln(20)
        self.set_font("courier", size=24)
        self.set_text_color(255, 255, 255)
        self.cell(0, 213, self.name, align="C")
        self.output("shirtificate.pdf")


def main():
    pdf = shirtificate(input("Name: ") + " took CS50")
    pdf.generate_picture()


if __name__ == "__main__":
    main()