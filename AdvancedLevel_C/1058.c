#include <stdio.h>

struct Hogwarts {
    int Galleon, Sickle, Knut;
} A, B, C;

int main()
{
    scanf("%d.%d.%d", &A.Galleon, &A.Sickle, &A.Knut);
    scanf("%d.%d.%d", &B.Galleon, &B.Sickle, &B.Knut);

    C.Knut = A.Knut + B.Knut;
    C.Sickle = A.Sickle + B.Sickle + C.Knut / 29;
    C.Galleon = A.Galleon + B.Galleon + C.Sickle / 17;
    C.Knut %= 29;
    C.Sickle %= 17;

    printf("%d.%d.%d\n", C.Galleon, C.Sickle, C.Knut);

    return 0;
}
