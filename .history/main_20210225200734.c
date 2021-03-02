#include<stdio.h>



int main()
{

    for(int i=0;i<3;i++){
        for(int j=0;j<999999999;j++)
            printf("");
        printf("percent %d\n",i);
    }

    do{
        int thankful = 0;
        char f = getchar();
        if(f == 'w')
            thankful = 1;

    }while(! thankful)
    
    getchar();
    return 0;
}
