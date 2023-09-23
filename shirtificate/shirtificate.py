from fpdf import FPDF

class shirtificate(FPDF):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def header(self):
        self.image("./shirtificate.png", 10, 70, 190)
        self.set_font("helvetica", "", 48)
        self.cell(0, 57, "CS50 Shirtificate", align="C")
        self.ln(20)

    def generate_shirt(self):
        self.add_page(orientation="portrait", format="a4")
        self.set_font("helvetica", size=24)
        self.set_text_color(255, 255, 255)
        self.cell(0, 213, f"{self.name} took CS50", align="C")
        self.output("shirtificate.pdf")


def main():
    name = input("Name: ")
    pdf = shirtificate(name)
    pdf.header()
    pdf.generate_shirt()


if __name__ == "__main__":
    main()