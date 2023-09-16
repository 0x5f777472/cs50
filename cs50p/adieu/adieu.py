import inflect
p = inflect.engine()
names = list()
while True:
    try:
        name = input("Name: ")
    except:
        print()
        break
    names.append(name)
print(f"Adieu, adieu, to {p.join(names)}")