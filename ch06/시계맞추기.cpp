#include <stdio.h>

#define INF 987654321


int C;
int clock[20];
int min;

void turn_clock(int num);
void push_clock(int num);

void push_all_buttons(int button, int cnt) {
    // base case: iterate through all buttons
    // buttons 한 번씩 다 거쳐야 버튼별 몇 번 눌렀는지 확인 가능
    if (button == 10) {
        // update min
        bool complete = true;
        for (int i=0; i<16; i++) {
            if (clock[i] != 12){
                complete = false;
                break;
            }
        }
        if (complete && min > cnt) min = cnt;
        return;
    }

    // printf("curr button: %d\n", button);
    // printf("cnt: %d\n", cnt);
    // printf("Curr clock\n");
    // for (int j=0; j<16; j++) {
    //         printf("%d ", clock[j]);
    //     }
    //     printf("\n");
    //     printf("\n");

    // each button: num click 0~4
    for (int i=0; i<4; i++) {
        push_all_buttons(button + 1, cnt + i);
        push_clock(button);
    }
}

int main() {
    scanf("%d", &C);
    for (int i=0; i<C; i++) {
        // init
        min = INF;
        for (int j=0; j<16; j++) {
            scanf("%d", &clock[j]);
        }

        // for (int j=0; j<16; j++) {
        //     printf("%d ", clock[j]);
        // }
        // printf("\n");

        push_all_buttons(0, 0);
        if (min == INF) min = -1;
        printf("%d\n", min);
    }
}

void turn_clock(int num) {
    clock[num] += 3;
    if (clock[num] > 12) {
        clock[num] = 3;
    }
}

void push_clock(int num) {
    switch (num) {
        case 0:
            turn_clock(0);
            turn_clock(1);
            turn_clock(2);
            break;
        case 1:
            turn_clock(3);
            turn_clock(7);
            turn_clock(9);
            turn_clock(11);
            break;
        case 2:
            turn_clock(4);
            turn_clock(10);
            turn_clock(14);
            turn_clock(15);
            break;
        case 3:
            turn_clock(0);
            turn_clock(4);
            turn_clock(5);
            turn_clock(6);
            turn_clock(7);
            break;
        case 4:
            turn_clock(6);
            turn_clock(7);
            turn_clock(8);
            turn_clock(10);
            turn_clock(12);
            break;
        case 5:
            turn_clock(0);
            turn_clock(2);
            turn_clock(14);
            turn_clock(15);
            break;
        case 6:
            turn_clock(3);
            turn_clock(14);
            turn_clock(15); 
            break;
        case 7:
            turn_clock(4);
            turn_clock(5);
            turn_clock(7);
            turn_clock(14);
            turn_clock(15);
            break;
        case 8:
            turn_clock(1);
            turn_clock(2);
            turn_clock(3);
            turn_clock(4);
            turn_clock(5);
            break;
        case 9:
            turn_clock(3);
            turn_clock(4);
            turn_clock(5);
            turn_clock(9);
            turn_clock(13);
            break;
    }
}
