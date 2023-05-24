#include <stdio.h>

#ifndef max
#define max(a, b) a > b ? a : b
#endif

#ifndef min
#define min(a, b) a > b ? b : a
#endif


int C, N;
int fence[20010];

// left sum, right sum은 재귀적으로 구하고, middle sum은 직접 구해야 한다
int maxArea(int left, int right) {
    // base case: 한 칸
    if (left == right) return fence[left];

    int mid = (left + right) / 2;

    // left sum, right sum
    int left_sum = maxArea(left, mid);
    int right_sum = maxArea(mid+1, right);
    int sum_either_side = max(left_sum, right_sum);

    // middle sum
    // 가운데 중심으로 높이 큰 쪽으로 한 칸씩
    // 한 칸씩 나갈 때마다, 새로 수정된 높이 반영하여 sum 업데이트
    // sum이 반드시 매번 업데이트될 필요는 없다 - 기존 sum값과 비교하여 max로 업데이트
    int i = mid;
    int j = mid+1;
    int height = min(fence[i], fence[j]);
    int sum_both_sides = 2 * height;

    while (i > left && j < right) {
        if (fence[i-1] > fence[j+1]) {
            i--;
            height = min(height, fence[i]);
        }
        else if (fence[i-1] < fence[j+1]) {
            j++;
            height = min(height, fence[j]);
        }
        else {
            i--; j++;
            height = min(height, fence[i]);
        }
        sum_both_sides = max(sum_both_sides, (j-i+1) * height);
    }
    // 끝까지 업데이트
    while(i > left) {
        i--;
        height = min(height, fence[i]);
        sum_both_sides = max(sum_both_sides, (j-i+1) * height);
    }
    while(j < right) {
        j++;
        height = min(height, fence[j]);
        sum_both_sides = max(sum_both_sides, (j-i+1) * height);
    }

    return max(sum_either_side, sum_both_sides);
}

int main() {
    scanf("%d", &C);
    for (int t=0; t<C; t++) {
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            scanf("%d", &fence[i]);
        }
        printf("%d\n", maxArea(0, N-1));
    }
}