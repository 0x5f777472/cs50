import inflect
p = inflect.engine()
names = list()
while True:
    name = input("Name: ")
    if name == "penis":
        break
    names.append(name)
print(p.join(names))