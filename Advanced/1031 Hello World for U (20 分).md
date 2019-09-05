# 1031 Hello World for U (20 分)

Given any string of $N (≥5)$ characters, you are asked to form the characters into the shape of `U`. For example, `helloworld` can be printed as:
`
h  d
e  l
l  r
lowo
`
That is, the characters must be printed in the original order, starting top-down from the left vertical line with $n_1$ characters, then left to right along the bottom line with $n_2$ characters, and finally bottom-up along the vertical line with $n_3$ characters. And more, we would like `U` to be as squared as possible -- that is, it must be satisfied that
$n_1 = n_3 = max\{k | k ≤ n_2 for all 3 ≤ n_2 ≤ N\} with n_1 + n_2 + n_3 - 2 = N$.

## Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

## Output Specification:
For each test case, print the input string in the shape of U as specified in the description.

## Sample Input:
helloworld!

## Sample Output:
h   !
e   d
l   l
lowor
