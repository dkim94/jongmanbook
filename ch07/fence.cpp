#include <stdio.h>

int C, N;
int fence[20010];

int maxArea(int left, int right) {
    if (left == right) return fence[left];

    int mid = (left + right) / 2;
    int left_sum, right_sum = 0;
    
    // get left sum
    int sum = 0;
    // height 조절해가면서 무언가를?
    int curr_height = 0;
    sum
    for (int i = mid; i >= left; i--) {
        sum += fence[i];
        left_sum = sum > left_sum ? sum : left_sum;
    }

    // get right sum
    sum = 0;
    for (int i = mid+1; i <= right; i++) {
        sum += fence[i];
        right_sum = sum > right_sum
    }

}

int main() {
    scanf("%d", &C);
    for (int t=0; t<C; t++) {
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            scanf("%d", &fence[i]);
        }
    }
}