camel = input("camelCase: ")
camel_split = []
last = 0
for i, c in enumerate(camel):
    if c.isupper():
        camel_split.append(camel[last:i])
        print(f"last: {last}, i: {i}, c: {c}")
        last = i
print(camel_split)