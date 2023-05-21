#include <stdio.h>


int C, n, m;
bool is_picked[10];
bool are_friends[10][10];
int cnt;


void cnt_friend_combinations(int n) {
    int curr = -1;
    // base case: everyone has friend
    for (int i=0; i<n; i++) {
        if (!is_picked[i]) {
            curr = i;
            break;
        }
    }
    if (curr == -1) {
        cnt++;
        return;
    }
    // start from smallest idx who is not picked yet - 순서 강제
    for (int i=curr+1; i<n; i++) {
        if (!is_picked[i] && are_friends[i][curr]) {
            is_picked[i] = true;
            is_picked[curr] = true;
            cnt_friend_combinations(n);
            is_picked[i] = false;
            is_picked[curr] = false;
        }
    }

}

int main() {
    scanf("%d", &C);
    for (int i=0; i<C; i++) {
        scanf("%d %d", &n, &m);

        // init
        cnt = 0;
        for (int j=0; j<n; j++) {
            is_picked[j] = false;
            for (int k=0; k<n; k++) {
                are_friends[j][k] = false;
            }
        }
        // set friends
        for (int j=0; j<m; j++) {
            int f1, f2 = 0;
            scanf("%d %d", &f1, &f2);
            are_friends[f1][f2] = true;
            are_friends[f2][f1] = true;
        }

        cnt_friend_combinations(n);
        printf("%d\n", cnt);
           
    }
}