
num = input()
digit = [0 for i in range(10)]
for c in num:
    digit[int(c)] += 1

num = str(2 * int(num))

for c in num:
    digit[int(c)] -= 1

no = bool([x for x in digit if x])
print(("Yes", "No")[no])
print(num)
