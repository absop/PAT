# 1015 Reversible Primes (20 分)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers $N (< 10^5)$ and $D (1 < D ≤ 10)$, you are supposed to tell if $N$ is a reversible prime with radix $D$.

## Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers $N$ and $D$. The input is finished by a negative $N$.

## Output Specification:
For each test case, print in one line Yes if $N$ is a reversible prime with radix $D$, or No if not.

## Sample Input:
73 10
23 2
23 10
-2

## Sample Output:
Yes
Yes
No
