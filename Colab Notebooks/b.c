#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, sq;
        int count = 0;
        scanf("%d", &n);
        sq = sqrt(n);
        for (int i = 1; i <= sq; i++)
            for (int j = 1; j <= sq; j++)
                if ((i * i) + (j * j) == n)
                    count++;
        printf("%d\n", count);
    }

    return 0;
}