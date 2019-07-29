def readbook():
    book = [input() for i in range(6)]
    for key in book[3].split(" "):
        itmes[3].setdefault(key, []).append(book[0])

    for i in (1, 2, 4, 5):
        itmes[i].setdefault(book[i], []).append(book[0])


itmes = [None, {}, {}, {}, {}, {}]

for i in range(int(input())):
    readbook()

for i in range(int(input())):
    q = input()
    print(q)
    n, caption = int(q[0]), q[3:]
    if caption in itmes[n]:
        print(*sorted(itmes[n][caption]), sep="\n")
    else:
        print("Not Found")
