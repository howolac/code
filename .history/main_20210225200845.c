#include<stdio.h>



int main()
{

    for(int i=0;i<3;i++){
        for(int j=0;j<999999999;j++)
            printf("");
        printf("percent %d\n",i);
    }

    do{
        int k = 0;
        char f = getchar();
        if(f == 'w')
            k = 1;

    }while(k == 1)
    
    getchar();
    return 0;
}
