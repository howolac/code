#include<stdio.h>



int main()
{

    for(int i=0;i<3;i++){
        for(int j=0;j<999999999;j++)
            printf("");
        printf("percent %d\n",i);
    }

    
    int k = 0;
    do{

       
        char f = getchar();

        if(f == 'w')
            k = 1;

    }while( !k);

    getchar();
    return 0;
}
