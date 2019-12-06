sets = []

for i in range(int(input())):
    numbers = list(map(int, input().split(" ")))
    sets.append(set(numbers[1:]))

for i in range(int(input())):
    p, q = input().split(" ")
    p, q = int(p) - 1, int(q) - 1
    Nc = len(sets[p].intersection(sets[q]))
    Nt = len(sets[p].union(sets[q]))
    print("%.1f%%" % (Nc / Nt * 100))
