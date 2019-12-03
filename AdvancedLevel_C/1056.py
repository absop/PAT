parser = lambda: map(int, input().split(" "))
ngroup = lambda n: (n + g - 1) // g

n, g = list(parser())
mouses = list(map(list, zip(parser(), parser())))
pmouses = [mouses[mouse[1]] for mouse in mouses]

maxi = 0
while n > 1:
    newn = ngroup(n)
    rank = newn + 1
    for i in range(newn):
        maxi = i * g
        for j in range(maxi + 1, min(maxi + g, n)):
            if pmouses[j][0] < pmouses[maxi][0]:
                pmouses[j][1] = rank
            else:
                pmouses[maxi][1] = rank
                maxi = j
        pmouses[i] = pmouses[maxi]
    n = newn
pmouses[maxi][1] = 1

print(*[mouse[1] for mouse in mouses], sep=" ")
