camel = input("camelCase: ")
camel_split = []
for i, c in enumerate(camel):
    if c.isupper():
        last = 0
        camel_split.append(camel[last:i])
        last = i
print(camel_split)