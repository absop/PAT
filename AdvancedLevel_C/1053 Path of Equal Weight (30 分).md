# 1053 Path of Equal Weight (30 分)

Given a non-empty tree with root $R$, and with weight $W_i$ assigned to each tree node $T_i$. The **weight of a path from** $R$ **to** $L$ is defined to be the sum of the weights of all the nodes along the path from $R$ to any leaf node $L$.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in the following figure: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: $\{10 5 2 7\}$, $\{10 4 10\}$, $\{10 3 3 6 2\}$ and $\{10 3 3 6 2\}$, which correspond to the red edges in the figure.
![1053](../image/1053.jpg)

## Input Specification:
Each input file contains one test case. Each case starts with a line containing $0 < N ≤ 100$, the number of nodes in a tree, $M (< N)$, the number of non-leaf nodes, and $0 < S < 2^{30}$, the given weight number. The next line contains $N$ positive numbers where $W_i (< 1000)$ corresponds to the tree node $T_i$. Then $M$ lines follow, each in the format:
```
ID K ID[1] ID[2] ... ID[K]
```

where `ID` is a two-digit number representing a given non-leaf node, `K` is the number of its children, followed by a sequence of two-digit `ID`'s of its children. For the sake of simplicity, let us fix the root ID to be `00`.

## Output Specification:
For each test case, print all the paths with weight S in **non-increasing** order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

Note: sequence $\{A_1, A_2, \cdots, A_n\}$ is said to be **greater than** sequence $\{B_1, B_2, \cdots, B_n\}$ if there exists 1 ≤ k < min{n,m} such that $A_i = B_i$ for $i = 1, \cdots, k$, and $A_{k+1} > B_{k+1}$.

## Sample Input:
```
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
```

## Sample Output:
```
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
```
