#include <stdio.h>
#include <stdlib.h>

#define N 20
int p = 0;

struct score
{
    int gui, Cla, ave;

} s;
//学生成绩结构体done
struct student
{
    int num;
    char name[10], sex[5];
    int year, month, Day;
    struct score s;
} stu[N], t;
//学生个人信息结构体done

void InputData(int x)
{
    int count;

    if (x == 0 || x == 1)
    {
        printf("有多少个学生？");
        scanf("%d", &count);
    }

    if (x == 0)
    {
        p = 0;
    }
    count = p + count;

    if (x == 0 || x == 1)
    {
        while (p != count)
        {
            printf("学生%d的学号：", p + 1);
            scanf("%d", &stu[p].num);
            printf("学生%d的姓名：", p + 1);
            scanf("%s", &stu[p].name);
            printf("学生%d的性别（boy or girl）：", p + 1);
            scanf("%s", &stu[p].sex);
            printf("学生%d出生的年份(2000/2001/2002)为：", p + 1);
            scanf("%d", &stu[p].year);
            printf("学生%d出生的月份为：", p + 1);
            scanf("%d", &stu[p].month);
            printf("学生%d出生的日期为：", p + 1);
            scanf("%d", &stu[p].Day);
            printf("学生%d计导的成绩：", p + 1);
            scanf("%d", &stu[p].s.gui);
            printf("学生%dc语言的成绩：", p + 1);
            scanf("%d", &stu[p].s.Cla);
            printf("\n");

            stu[p].s.ave = (stu[p].s.gui + stu[p].s.Cla) / 2;
            p++;
        }
    }

    if (x != 0 && x != 1)
    {
        int i;

        for (i = 0; i < p; i++)
            if (stu[i].num == x)
            {
                printf("学生%d的学号：", i + 1);
                scanf("%d", &stu[i].num);
                printf("学生%d的姓名：", i + 1);
                scanf("%s", &stu[i].name);
                printf("学生%d的性别（boy or girl）：", i + 1);
                scanf("%s", &stu[i].sex);
                printf("学生%d出生的年份(2000/2001/2002)为：", i + 1);
                scanf("%d", &stu[i].year);
                printf("学生%d出生的月份为：", i + 1);
                scanf("%d", &stu[i].month);
                printf("学生%d出生的日期为：", i + 1);
                scanf("%d", &stu[i].Day);
                printf("学生%d计导的成绩：", i + 1);
                scanf("%d", &stu[i].s.gui);
                printf("学生%dc语言的成绩：", i + 1);
                scanf("%d", &stu[i].s.Cla);

                stu[p].s.ave = (stu[p].s.gui + stu[p].s.Cla) / 2;
                printf("\n");
            }
    }

    printf("录入成功！\n", p + 1);
    printf("按任意键继续！\n");

    getchar();
    getchar();

    return;
}
//完全输入并新建数据库

void del(int x)
{
    int i, j;

    for (i = 0; i < p; i++)
        if (stu[i].num == x)
        {
            for (j = i; j < (p); j++)
                stu[j] = stu[j + 1];

            p--;

            return;
        }
}

void SaveData()
{
    FILE *fp;
    fp = fopen("s.txt", "w");

    int i;

    for (i = 0; i < p; i++)
        fprintf(fp, "%d %s %s %d %d %d %d %d %d\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].month, stu[i].Day, stu[i].s.gui, stu[i].s.Cla, stu[i].s.ave);

    printf("存入文件成功!!!\n");
    printf("按任意键继续！！\n");

    getchar();
    getchar();

    fclose(fp);

    return;
}
//完整保存信息到文件

void ReadData()
{
    p = 0;
    FILE *fp;
    fp = fopen("s.txt", "r");
    while (1)
    {
        if (fscanf(fp, "%d %s %s %d %d %d %d %d %d\n", &stu[p].num, &stu[p].name, &stu[p].sex, &stu[p].year, &stu[p].month, &stu[p].Day, &stu[p].s.gui, &stu[p].s.Cla, &stu[p].s.ave) > 0)
            p++;
        else
            break;
    }

    fclose(fp);

    printf("读取文件成功，共录入学生信息%d条，创建数据库成功！！！\n", p);
    printf("按任意键继续......\n");

    getchar();

    return;
}
//完全读取学生信息,创建数据库

int sort(int x)
{
    int i, j;

    if (x == 1)
    {
        for (i = 0; i < p; i++)
            for (j = i; j < p; j++)
                if (stu[i].s.ave < stu[j].s.ave)
                {
                    t = stu[j];
                    stu[j] = stu[i];
                    stu[i] = t;
                }
    }
    else if (x == 2)
    {
        for (i = 0; i < p; i++)
            for (j = i; j < p; j++)
                if (stu[i].s.ave > stu[j].s.ave)
                {
                    t = stu[j];
                    stu[j] = stu[i];
                    stu[i] = t;
                }
    }

    return;
}
//按平均成绩排序done

void Browse(int x)
{

    int i, count = 1;
    char t[10];

    printf("学号    \t姓名    \t性别  \t计导 \tc语言\t平均成绩\t生日\t\n");

    if (x != 0)
    {
        for (i = 0; i < p; i++)
            if (stu[i].num == x)
            {
                if (stu[i].s.ave < 60)
                    t[10] = '不及格';
                else
                    t[10] = '及格';
                printf("%-8d\t%-4s\t%-s\t%-d\t%-d\t%-d\t%-s\t%d-%d-%d\t\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].s.gui, stu[i].s.Cla, stu[i].s.ave, t, stu[i].year, stu[i].month, stu[i].Day);

                printf("\n按任意键继续！\n");
                getchar();
                getchar();

                return;
            }
    }

    for (i = 0; i < p; i++)
    {
        count++;

        if (count % 10 == 0)
        {
            printf("按任意键翻页");

            getchar();
        }
        if (stu[i].s.ave < 60)
            t[10] = '不及格';
        else
            t[10] = '及格';

        printf("%-8d\t%-8s\t%-s\t%-d\t%-d\t%-d\t%-s\t%d-%d-%d\t\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].s.gui, stu[i].s.Cla, stu[i].s.ave, t, stu[i].year, stu[i].month, stu[i].Day);
    }

    printf("\n按任意键继续！\n");

    getchar();
    getchar();
}
//把所有学号，姓名，性别，成绩，及格否，生日打印出来

void InfSta()
{
    int x;

    printf("1.按性别统计\n2.按出生年统计人数\n3.按平均成绩统计人数\n");
    scanf("%d", &x);

    if (x == 1)
    {
        int count = 0;

        for (x = 0; x < p; x++)
        {
            if (strcmp(stu[x].sex, "boy") == 0)

                count++;
        }
        printf("男生人数为%d\n女生人数为%d", count, p - count);
    }

    else if (x == 2)
    {
        int count[3] = {0, 0, 0};

        for (x = 0; x < p; x++)
        {
            if (stu[x].year == 2000)
                ++count[0];
            else if (stu[x].year == 2001)
                ++count[1];
            else if (stu[x].year == 2002)
                ++count[2];
        }

        printf("2000年的有%d个\n2001的有%d个\n2002的有%d个\n", count[0], count[1], count[2]);
    }
    else if (x == 3)
    {
        int count[2] = {0, 0};

        for (x = 0; x < p; x++)
        {
            if (stu[x].s.ave < 60)
                ++count[0];
            else if (stu[x].s.ave >= 60 && stu[x].s.ave < 80)
                count[1]++;
        }
        printf("平均成绩<60的有%d人\n", count[0]);
        printf("60<=平均成绩<80的有%d人\n", count[1]);
        printf("平均成绩>80的有%d人", p + 1 - count[0] - count[1]);
    }
    printf("按任意键继续！");

    getchar();
    getchar();
    return;
}

int Vote()
{
    sort(1);

    int i, j, x, count;
    int cou[5] = {0, 0, 0, 0, 0};

    printf("票数最高的五位同学分别是:\n");
    
    for (i = 0; i < 5; i++)
    {
        printf("%d.%s\n", i + 1, stu[i].name);
    }

    printf("有多少个同学投票：\n>>");
    scanf("%d", &x);

    for (i = 0; i < x; i++)
    {
        printf("第%d位同学投票给谁:\n>>", i + 1);
        scanf("%d", &j);
        cou[j - 1]++;
    }

    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
            if (cou[i] < cou[j])
            {
                x = cou[i];
                cou[i] = cou[j];
                cou[j] = x;
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }

    if (cou[0] == cou[1])
        printf("至少两人的票数相同，请重新进行投票！\n");
    else
        printf("票数最高的同学是%s\n", stu[0].name);

    printf("按任意键继续！！");
    getchar();
    getchar();
}

void Search()
{
    int i, number;
    char t;
    printf("输入学号：");
    scanf("%d", &number);
    printf("学号\t姓名\t性别\t计导\tc语言\t  \t生日\t");
    for (i = 0; i < p; i++)
        if (stu[i].num == number)
        {
            if (stu[i].s.ave < 60)
                t = '不及格';
            else
                t = '及格';
            printf("%-4d\t%-8d\t%-6s\t%-6s\t%-4d\t%-4d\t%-10s\t%d-%d-%d\t\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].s.gui, stu[i].s.Cla, t, stu[i].year, stu[i].month, stu[i].Day);
        }
    printf("按任意键继续！");
    getchar();
}

void fix()
{
    int x;
    printf("要修改学生信息的同学的学号：\n>>");
    scanf("%d", &x);
    Search(x);
}

void fun(int x)
{
    int number;

    switch (x)
    {
    case 1:
        InputData(0);
        break;

    case 2:
        InputData(1);
        break;

    case 3:
        Browse(0);
        break;

    case 4:
        printf("1.按平均成绩从大到小排序：   2.按平均成绩从小到大排序\n>>");
        scanf("%d", &number);
        sort(number);
        break;

    case 5:
        InfSta();
        break;

    case 6:
        printf("要查询的学生的学号：\n>>");
        scanf("%d", &number);
        Browse(number);
        break;

    case 7:
        printf("要修改的学生的学号：\n>>");
        scanf("%d", &number);
        InputData(number);
        break;

    case 8:
        printf("要删除的学生号：");
        scanf("%d", &number);
        del(number);

    case 9:
        Vote();
        break;

    case 10:
        SaveData();
        break;
    }
}
void menu()
{
    system("cls");
    printf("===================================\n");
    printf("           1---新建数据库\n");
    printf("           2---追加数据库\n");
    printf("           3---学生信息浏览\n");
    printf("           4---学生信息排序\n");
    printf("           5---学生信息统计\n");
    printf("           6---学生信息查询\n");
    printf("           7---学生信息修改\n");
    printf("           8---学生信息删除\n");
    printf("           9---学生选票\n");
    printf("           10---学生信息存储\n");
    printf("           0---退出\n");
    printf("===================================\n");
    printf("           请输入你的选择：\n");
    return;
}
void MyMenu()
{
    int x;
    while (1)
    {
        menu();
        printf(">>");
        scanf("%d", &x);
        fun(x);
        if (x == 0)
            return;
    }
}

int main()
{
    ReadData();
    MyMenu();
    return 0;
}
