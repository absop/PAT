#include <stdio.h>

#define iszero(x) (-1e-1 < (x) && (x) < 1e-1)
typedef struct _cplex {
    double re, im;
} cplex_t;

cplex_t calc(char op, cplex_t x, cplex_t y)
{
    cplex_t res;
    switch (op) {
        case '+':
            res.re = x.re + y.re;
            res.im = x.im + y.im;
            break;
        case '-':
            res.re = x.re - y.re;
            res.im = x.im - y.im;
            break;
        case '/':
            res.im = y.re * y.re + y.im * y.im;
            y.re /= res.im;
            y.im /= res.im;
            y.im = -y.im;
        case '*':
            res.re = x.re * y.re - x.im * y.im;
            res.im = x.re * y.im + y.re * x.im;
            break;
    }
    return res;
}

void printcplex(cplex_t z)
{
    printf("(%.1lf", z.re);
    if (z.im >= 0) putchar('+');
    printf("%.1lfi)", z.im);
}

void printexpr(cplex_t x, char op, cplex_t y)
{
    cplex_t z = calc(op, x, y);
    printcplex(x);
    printf(" %c ", op);
    printcplex(y);
    printf(" = ");

    if (!iszero(z.re)) {
        printf("%.1lf", z.re);
        if (!iszero(z.im)) {
            if (z.im > 0.0) putchar('+');
            printf("%.1lfi", z.im);
        }
    }
    else if (!iszero(z.im))
        printf("%.1lfi", z.im);
    else printf("0.0");

    putchar('\n');
}

int main()
{
    cplex_t x, y;
    scanf("%lf %lf", &x.re, &x.im);
    scanf("%lf %lf", &y.re, &y.im);
    printexpr(x, '+', y);
    printexpr(x, '-', y);
    printexpr(x, '*', y);
    printexpr(x, '/', y);

    return 0;
}
