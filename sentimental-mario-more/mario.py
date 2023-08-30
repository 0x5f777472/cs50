# TODO
while True:
    height = int(input("Height: "))
    if 1 <= height <= 8:
        for i in range(1, height + 1):
            for j in range(height - i):
                print(" ", end="")
                j+=1
            for j in range(i):
                print("#", end="")
                j+=1
            print("  ", end="")
            for j in range(i):
                print("#", end="")
                j+=1
            print("")
            i+=1
        break

