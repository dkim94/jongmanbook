#include <stdio.h>
#include <vector>

using std::vector;


int sum = 0;

void cnt_all_combinations(int n, int k, vector<int>& picked) {
    if (k == 0) sum++;
    else {
        int smallest = picked.empty() ? 1 : picked.back() + 1;
        for (int i = smallest; i <= n; i++) {
            picked.push_back(i);
            cnt_all_combinations(n, k-1, picked);
            picked.pop_back();
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> picked;

    cnt_all_combinations(n, k, picked);
    printf("%d\n", sum);
}

