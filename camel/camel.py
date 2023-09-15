camel = input("camelCase: ")
camel_split = []
last = 0
for i in range(len(camel)):
    if camel[i].isupper():
        camel_split.append(camel[last:i])
        last = i
camel_split.append(camel[last:])
snake = "_".join(camel_split)
snake = snake.lower()
print(f"snake_case: {snake}")
# wow this is bad
# this could definitely been better somehow :------|