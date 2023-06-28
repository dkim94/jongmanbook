#include <stdio.h>
#include <vector>

using std::vector;

int n, k;
vector<int> picked;
int count;

void nck(int n, int k) {
    if (k == 0) {
        for (int i=0; i<picked.size(); i++) {
            printf("%d ", picked[i]);
        }
        printf("\n");
        count++;
        return;
    }
    int curr = picked.empty() ? 0 : picked.back() + 1;
    for (int i=curr; i<n; i++) {
        picked.push_back(i);
        nck(n, k-1);
        picked.pop_back();
    }
}

int main() {
    scanf("%d %d", &n, &k);
    count = 0;
    nck(n, k);
    printf("count: %d\n", count);
}

