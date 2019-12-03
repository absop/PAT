# Python 怎么也过不了，算了！
maxn, top = 100010, 0
stack = [0 for i in range(maxn)]
sums = [0 for i in range(maxn)]
lowbit = lambda n: n & (- n)

def update(i, v):
    while i < maxn:
        sums[i] += v
        i += lowbit(i)

def getsum(i):
    sum = 0
    while i >= 1:
        sum += sums[i]
        i -= lowbit(i)
    return sum

def median():
    left, right, k = 1, maxn, (top + 1) >> 1
    while left < right:
        mid = (left + right) >> 1
        if(getsum(mid) >= k):
            right = mid
        else:
            left = mid + 1
    return left


for i in range(int(input())):
    command = input()
    if command[1] == 'e':
        if top > 0:
            print(median())
        else:
            print("Invalid")

    elif command[1] == 'o':
        if top > 0:
            top -= 1
            update(stack[top], -1)
            print(stack[top])
        else:
            print("Invalid")

    else:
        stack[top] = int(command[5:])
        update(stack[top], 1)
        top += 1
