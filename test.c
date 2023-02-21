#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dec(int a)
{
    int num = 0;
    for (int i = 0; a; i++)
    {
        // printf("sdf\n");
        if (a % 10)
        {
            int a = i, temp = 1;
            while (a)
            {
                temp *= 2;
                a--;
            }
            num += temp;
        }
        a /= 10;
    }
    return num;
}

int bin(int a)
{
    char s[100];
    for (int i = 0; a; i++)
    {
        // printf("sdf\n");
        if (a % 2)
        {
            printf("11\n");
            s[i] = '1';
        }
        else
        {

            printf("00\n");
            s[i] = '0';
        }
        a /= 2;
    }
    char n[strlen(s) + 1];
    int c = 0;
    for (int i = (strlen(s) - 1); i >= 0; i--)
    {
        n[c] = s[i];
        c++;
    }

    printf("===%s===\n", s);
    printf("===n %s===\n", n);
    // printf("===%d===\n", strlen(s));
    int num = atoi(n);
    printf("===%d===\n", num);
    return num;
}

int main()
{
    // int a = dec(10000);
    // printf("%d\n", a);
    // int b = bin(7);
    // printf("%d", b);
    int b = 12 & 25;
    printf("%d\n", b);

    // int num = 1011;
    // char str[50];
    // sprintf(str, "%d", num);
    // printf("%s", str);

    return 0;
}