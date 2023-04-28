#include <stdio.h>
#include <sys/wait.h>
#include <time.h>

int f()
{
    int static n = 8;
    return n--;
}

int main()
{
    for (f(); f(); f())
    {
        printf("%d", f());
        wait(1000);
    }

    return 0;
}