from fpdf import FPDF

class shirtificate(FPDF):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def header(self):
        self.image("shirtificate.png", 10, 70, 190)
        self.set_font("inconsolata", "", 48)
        self.cell(0, 57, "CS50 Shirtificate", align="C")
        self.ln(20)

    def generate_shirt(self):
        self.add_page()
        self.set_font("inconsolata", size=24)
        self.set_text_color(255, 255, 255)
        self.cell(0, 213, self.name, align="C")
        self.output("shirtificate.pdf")


def main():
    pdf = shirtificate(input("Name: ") + " took CS50")
    pdf.header()
    pdf.generate_shirt()


if __name__ == "__main__":
    main()