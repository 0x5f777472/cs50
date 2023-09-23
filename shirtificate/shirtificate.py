from fpdf import FPDF
pdf = FPDF()
pdf.add_page()



def main():
    name = input("Name: ").strip() + " took CS50"

if __name__ == "__main__":
    main()