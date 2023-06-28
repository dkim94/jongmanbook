#include <stdio.h>

#ifndef MAX
#define MAX(x, y) (x > y ? x : y)
#endif

int C, n;
int S[510];
int cache[510];

int lis(int curr)
{ // curr index부터 시작하는 부분증가수열의 길이
    if (cache[curr] != -1)
        return cache[curr];

    int max_len = 1;
    for (int i = curr + 1; i < n; i++)
    {
        if (S[i] > S[curr])
        {
            max_len = MAX(1 + lis(i), max_len);
            cache[curr] = max_len;
        }
    }
    return max_len;
}

int main()
{
    scanf("%d", &C);
    for (int t = 0; t < C; t++)
    {
        scanf("%d", &n);

        // init cache
        for (int i = 0; i < 500; i++)
        {
            cache[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &S[i]);
        }
        int max_len = 0;
        for (int i = 0; i < n; i++)
        {
            int result = lis(i);
            max_len = max_len > lis(i) ? max_len : result;
        }
        printf("%d\n", max_len);
    }
}