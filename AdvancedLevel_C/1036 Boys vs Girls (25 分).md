# 1036 Boys vs Girls (25 分)

This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

## Input Specification:
Each input file contains one test case. Each case contains a positive integer $N$, followed by $N$ lines of student information. Each line contains a student's `name`, `gender`, `ID` and `grade`, separated by a space, where `name` and `ID` are strings of no more than 10 characters with no space, `gender` is either `F` (female) or `M` (male), and `grade` is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

## Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference $grade_F − grade_​M$. If one such kind of student is missing, output `Absent` in the corresponding line, and output `NA` in the third line instead.

## Sample Input 1:
```
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
```

## Sample Output 1:
```
Mary EE990830
Joe Math990112
6
```

## Sample Input 2:
```
1
Jean M AA980920 60
```

## Sample Output 2:
```
Absent
Jean AA980920
NA
```
