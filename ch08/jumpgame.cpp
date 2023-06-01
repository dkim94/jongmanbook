#include <stdio.h>

int C, n;
int table[110][110];

// 1. 완전탐색
int dy[2] = {0, 1};
int dx[2] = {1, 0};

bool flag = false;

void jump(int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        flag = true;
        return;
    }
    int num_steps = table[i][j];
    for (int type = 0; type < 2; type++)
    {
        i += num_steps * dy[type];
        j += num_steps * dx[type];
        if (i < n && j < n)
            jump(i, j);
        i -= num_steps * dy[type];
        j -= num_steps * dx[type];
    }
}

// 2. 점화식 (이게 아이디어!!!)
bool jump_recursion(int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return true;
    else if (i >= n || j >= n)
        return false;
    else
    {
        int step_size = table[i][j];
        return jump_recursion(i + step_size, j) || jump_recursion(i, j + step_size);
    }
}

// 3. DP
int cache[110][110];
bool jump_dp(int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return true;
    else if (i >= n || j >= n)
        return false;

    if (cache[i][j] != -1)
        return cache[i][j];
    int step_size = table[i][j];
    cache[i][j] = jump_dp(i + step_size, j) || jump_dp(i, j + step_size);
    return cache[i][j];
}

int main()
{
    scanf("%d", &C);
    for (int t = 0; t < C; t++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &table[i][j]);
            }
        }
        flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cache[i][j] = -1;
            }
        }

        bool result = jump_dp(0, 0);
        if (result)
            printf("YES\n");
        else
            printf("NO\n");
    }
}