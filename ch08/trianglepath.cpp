#include <stdio.h>

#ifndef MAX
#define MAX(x, y) x > y ? x : y
#endif

int C, n;
int triangle[110][110];

int max(int i, int j, int sum) // (i,j)에서, 지금까지 sum이 sum일 때
{
    if (i == n - 1)
        return sum + triangle[i][j];
    int below = max(i + 1, j, sum + triangle[i][j]);
    int below_right = max(i + 1, j + 1, sum + triangle[i][j]);
    return below > below_right ? below : below_right;
}

int main()
{
    scanf("%d", &C);
    for (int t = 0; t < C; t++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &triangle[i][j]);
                cache[i][j] = -1; // init cache
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                printf("%d ", triangle[i][j]);
            }
            printf("\n");
        }

        printf("#%d: %d\n", t, max(0, 0, 0));
    }
}