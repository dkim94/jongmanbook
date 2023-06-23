#include <stdio.h>

#ifndef MAX
#define MAX(x, y) (x > y ? x : y)
#endif

int C, n;
int triangle[110][110];
int cache[110][110];

int max(int i, int j) // (i,j)에서 맨 아래까지 최대 부분합
{
    if (i == n - 1)
        return triangle[i][j];
    if (cache[i][j] != -1)
        return cache[i][j];
    int below = max(i + 1, j);
    int below_right = max(i + 1, j + 1);
    cache[i][j] = triangle[i][j] + MAX(below, below_right);
    return cache[i][j];
}

int main()
{
    scanf("%d", &C);
    for (int t = 0; t < C; t++)
    {
        scanf("%d", &n);

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cache[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &triangle[i][j]);
            }
        }

        printf("%d\n", max(0, 0));
    }
}