#include<stdio.h>



int main()
{

    char d = 'd';
    printf("a=(int)%d\n",(int)(d));

    for(int i=68;i<=128;i++){
        printf("%d:%c\n",i,char(i));
        printf("\n");
    }

    puts("this is a text");
    printf("'\n'");



    getchar();
    return 0;
}
