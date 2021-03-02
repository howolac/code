#include<stdio.h>



int main()
{

    for(int i=0;i<49;i++){
        for(int j=0;j<999999999;j++)
            printf("");
        printf("percent %d\n",i);
    }
    
    getchar();
    return 0;
}
