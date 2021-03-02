#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, s, area;

    scanf("%f,%f,%f", &a, &b, &c);

    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("a=%f\tb=%f\tc=%f\n", a, b, c);
    printf("area=%f\n", area);

    getchar();

    return 0;
}