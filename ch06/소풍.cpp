#include <cstdio>

int C, n, m;
bool areFriends[15][15];
bool hasFriend[15];

int findFriend(int n, bool hasFriend[15]);
int findFriend_v2(bool hasFriend[15]);

int main() {
    scanf("%d", &C);
    for (int i=0; i<C; i++) {
        scanf("%d %d", &n, &m);

        // init
        for (int j=0; j<n; j++) {
            hasFriend[j] = false;
            for (int k=0; k<n; k++) {
                areFriends[j][k] = false;
            }
        }

        // set areFriends
        for(int j=0; j<m; j++) {
            int f1, f2 = 0;
            scanf("%d %d", &f1, &f2);
            areFriends[f1][f2] = true;
        }
        // test print
        // for (int j=0; j<n; j++) {
        //     for (int k=0; k<n; k++) {
        //         printf("%d %d %d\n", j, k, areFriends[j][k]);
        //     }
        // }

        // printf("%d\n", findFriend(n, hasFriend));
        printf("%d\n", findFriend_v2(hasFriend));
    }
}

// n: num people
// hasFriend: To check if people have formed a pair or not
int findFriend(int n, bool hasFriend[15]) {
    // base case: if everyone has pair, return 1
    // if someone do not has pair, start from there
    bool flag = true;
    int curr = 0;
    for (int i=0; i<n; i++) {
        if (hasFriend[i] == false) {
            curr = i;
            flag = false;
            break;
        }
    }
    if (flag) return 1;

    int cnt = 0;
    for (int i=curr+1; i<n; i++) {
        if (!hasFriend[i] && areFriends[curr][i]) {
            hasFriend[curr] = true;
            hasFriend[i] = true;
            cnt += findFriend(n, hasFriend);
            hasFriend[curr] = false;
            hasFriend[i] = false;
        }
    }
    return cnt;
}

// n does not change 
int findFriend_v2(bool hasFriend[15]) {
    // base case: if everyone has pair, return 1
    // if someone do not has pair, start from there
    bool flag = true;
    int curr = 0;
    for (int i=0; i<n; i++) {
        if (hasFriend[i] == false) {
            curr = i;
            flag = false;
            break;
        }
    }
    if (flag) return 1;

    int cnt = 0;
    for (int i=curr+1; i<n; i++) {
        if (!hasFriend[i] && areFriends[curr][i]) {
            hasFriend[curr] = true;
            hasFriend[i] = true;
            cnt += findFriend(n, hasFriend);
            hasFriend[curr] = false;
            hasFriend[i] = false;
        }
    }
    return cnt;
}