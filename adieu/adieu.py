import inflect
p = inflect.engine()
names = list()
while True:
    name = input("Name: ")
    names.append(name)
print(f"Adieu, adieu, to {p.join(names)}")