#include <stdio.h>

struct student_st
{
    char c;
    int score;
    const char *name;
};

static void show_student(struct student_st *stu)
{
    printf("c = %c, score = %d, name = %s\n", stu->c, stu->score, stu->name);
}

int main(void)
{
    // method 1: 按照成员声明的顺序初始化
    struct student_st s1 = {'A', 91, "Alan"};
    show_student(&s1);

    // method 2: 指定初始化，成员顺序可以不定，Linux 内核多采用此方式
    struct student_st s2 =
    {
        .name = "YunYun",
        .c = 'B',
        .score = 92,
    };
    show_student(&s2);
    s2 = (struct student_st){
        .name = "Ye Zhiqiu",
        .c = 'A',
        .score = 99,
    };

    // method 3: 指定初始化，成员顺序可以不定
    struct student_st s3 =
    {
        c: 'C',
        score: 93,
        name: "Wood",
    };
    show_student(&s3);

    return 0;
}
