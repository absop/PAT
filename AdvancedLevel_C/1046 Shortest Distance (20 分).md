# 1046 Shortest Distance (20 分)

The task is really simple: given $N$ exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

## Input Specification:
Each input file contains one test case. For each case, the first line contains an integer $N$ (in $[3, 10^​5]$), followed by $N$ integer distances $D_1, D_2, \cdots, D_N$, where $D_i$ is the distance between the $i$-th and the $(i+1)$-st exits, and $D_N$ is between the $N$-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer $M (≤ 10^4)$, with $M$ lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to $N$. It is guaranteed that the total round trip distance is no more than $10^7$.

## Output Specification:
For each test case, print your results in $M$ lines, each contains the shortest distance between the corresponding given pair of exits.

## Sample Input:
```
5 1 2 4 14 9
3
1 3
2 5
4 1
```

## Sample Output:
```
3
10
7
```
