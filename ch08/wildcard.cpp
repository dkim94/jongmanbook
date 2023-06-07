#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int C, n;
string W, S;
int cache[110][110];
vector<string> answers;

int compare(int i, int j)
{
    if (cache[i][j] != -1)
        return cache[i][j];

    int i_ = i;
    int j_ = j;

    // while (i < W.length() && j < S.length() && (W[i] == '?' || W[i] == S[j]))
    // {
    //     i++;
    //     j++;
    // }
    
    if (i < W.length() && S.length() && (W[i] == '?' || W[i] == S[j])) 
        return cache[i_][j_] = compare(i+1, j+1);

    if (i == W.length())
    {
        if (j == S.length())
            cache[i_][j_] = 1;
        else
            cache[i_][j_] = 0;
        return cache[i_][j_];
    }
    if (W[i] == '*')
    {
        // for (int k = 0; j + k <= S.length(); k++)
        // {
        //     if (compare(i + 1, j + k))
        //     {
        //         return cache[i_][j_] = 1;
        //     }
        // }
        // TODO: 이해하라..!
        if (compare(i+1, j) || (j < S.size() && compare(i, j+1)))
            return cache[i_][j_] = 1;
    }

    return cache[i_][j_] = 0;
}

int main()
{
    scanf("%d", &C);
    for (int t = 0; t < C; t++)
    {
        // scan input
        cin >> W;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            // init cache
            for (int j = 0; j < 110; j++)
            {
                for (int k = 0; k < 110; k++)
                {
                    cache[j][k] = -1;
                }
            }
            cin >> S;
            if (compare(0, 0))
                answers.push_back(S);
        }

        sort(answers.begin(), answers.end());

        cout<<"Answers"<<endl;
        for (int j = 0; j < answers.size(); j++)
            cout << answers[j] << endl;
        cout<<endl;

        answers.clear();
    }
}