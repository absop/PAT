# 1059 Prime Factors (25 分)

Given any positive integer $N$, you are supposed to find all of its prime factors, and write them in the format $N = p_1^{k_1} \times p_2^{k_2} \times \cdots \times p_m^{k_m}$.

## Input Specification:
Each input file contains one test case which gives a positive integer N in the range of **long int**.

## Output Specification:
Factor $N$ in the format $N$ `=` $p_1$ `^` $k_1$ `*` $p_2$ `^` $k_2$ `*` \cdots `*` $p_m$ `^` $k_m$, where $p_i$'s are prime factors of $N$ in increasing order, and the exponent $k_i$ is the number of $p_i$ -- hence when there is only one $p_i, k_i$ is 1 and must **NOT** be printed out.

## Sample Input:
```
97532468
```

## Sample Output:
```
97532468=2^2*11*17*101*1291
```
