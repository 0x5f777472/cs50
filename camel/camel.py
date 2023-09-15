camel = input("camelCase: ")
camel_split = []
last = 0
for i in range(len(camel)):
    if camel[i].isupper():
        camel_split.append(camel[last:i])
        last = i
    if i == len(camel) - 1:
        camel_split.append(camel[i:])
print(camel_split)