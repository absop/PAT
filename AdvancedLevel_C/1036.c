#include <stdio.h>
#include <string.h>

typedef struct _student_t {
    char name[12];
    char id[12];
    int grade;
} student_t;

int Nmale, Nfemale;
int femaleHighest = -1, maleLowest = 101;
student_t *ptrfemale, *ptrmale;
student_t maleStudents[101], femaleStudents[101];

int main()
{
    int N, grade;
    char gender, name[12], id[12];

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %c %s %d", name, &gender, id, &grade);
        if (gender == 'M') {
            strcpy(maleStudents[Nmale].name, name);
            strcpy(maleStudents[Nmale].id, id);
            maleStudents[Nmale++].grade = grade;
        }
        else /*if (gender == 'F')*/ {
            strcpy(femaleStudents[Nfemale].name, name);
            strcpy(femaleStudents[Nfemale].id, id);
            femaleStudents[Nfemale++].grade = grade;
        }
    }

    for (int i = 0; i < Nfemale; ++i) {
        if (femaleStudents[i].grade > femaleHighest) {
            ptrfemale = &femaleStudents[i];
            femaleHighest = ptrfemale->grade;
        }
    }
    for (int i = 0; i < Nmale; ++i) {
        if (maleStudents[i].grade < maleLowest) {
            ptrmale = &maleStudents[i];
            maleLowest = ptrmale->grade;
        }
    }

    if (femaleHighest != -1)
        printf("%s %s\n", ptrfemale->name, ptrfemale->id);
    else printf("Absent\n");

    if (maleLowest != 101)
        printf("%s %s\n", ptrmale->name, ptrmale->id);
    else printf("Absent\n");

    if (femaleHighest == -1 || maleLowest == 101)
        printf("NA\n");
    else printf("%d\n", femaleHighest - maleLowest);
}
