#include <stdio.h>
#include <time.h>

int cache[50][50];

int combination(int n, int r)
{
    printf("Called combination %d %d\n", n, r);
    if (n == r | r == 0)
        return 1;
    else
    {
        if (cache[n][r] == -1)
            cache[n][r] = combination(n, r - 1) + combination(n - 1, r - 1);
        return cache[n][r];
    }
}

int combination_slow(int n, int r) {
    printf("Called combination_slow %d %d\n", n, r);
    if (n == r | r == 0) return 1;
    return combination_slow(n, r-1) + combination_slow(n-1, r-1);
}

int main()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cache[i][j] = -1;
        }
    }

    clock_t start = clock();
    printf("%d\n", combination(49, 20));
    clock_t end = clock();
    printf("time: %ld\n", end - start);

    start = clock();
    printf("%d\n", combination_slow(49, 20));
    end = clock();
    printf("time: %ld\n", end - start);
}