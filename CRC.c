#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        if (a % 2)
        {
            s[i] = '1';
        }
        else
            s[i] = '0';
        a /= 2;
    }
    char n[strlen(s) + 1];
    int c = 0;
    for (int i = (strlen(s) - 1); i >= 0; i--)
    {
        n[c] = s[i];
        c++;
    }
    int num = atoi(n);
    return num;
}

int main()
{

    char data[100], divisor[100];
    scanf("%s%s", &data, &divisor);
    // printf("%s\n", data);
    // printf("%s\n", divisor);
    // printf("%d",strlen(divisor));

    char data_temp[100];
    strcpy(data_temp, data);
    int len = strlen(data) + strlen(divisor);
    for (int i = strlen(data); i < len - 1; i++)
    {
        data_temp[i] = '0';
    }
    printf("data in binary %s\n", data_temp);
    // printf("%s\n", data);
    // printf("%s\n", divisor);
    int num = 0, n;

    // str to int
    long long int data_i = atoi(data_temp);
    printf("data in binary %lld\n", data_i);
    int data_d = dec(data_i);
    printf("data in decimal %d\n", data_d);
    int divisor_i = atoi(divisor);
    int divisor_d = dec(divisor_i);
    printf("divisor in decimal %d\n", divisor_d);

    int rem = data_d & divisor_d;
    printf("rem iin decimal %d=+\n", rem);
    rem = bin(rem);
    printf("rem iin binary %d=+\n", rem);
    char rem_s[50];
    // int to stri
    sprintf(rem_s, "%d", rem);
    printf("--%s--\n", rem_s);

    int diff = strlen(divisor) - strlen(rem_s) - 1;
    int d = strlen(data);
    for (int i = strlen(data); i < diff + d; i++)
    {
        data[i] = '0';
        printf("=x=\n");
    }
    int c = 0;
    for (int i = strlen(data); i < (strlen(rem_s) + strlen(data)); i++)
    {
        data[i] = rem_s[c];
        c++;
    }
    printf("Final data to send : %s\n", data);

    // At receiver end

    int data_rec_d = atoi(data);
    data_rec_d = dec(data_rec_d);
    printf("data in decimal %d\n", data_rec_d);
    printf("data in decimal %d\n", divisor_d);
    int rem_rec_d = data_rec_d & divisor_d;
    printf("_____%d\n", rem_rec_d);

    return 0;
}