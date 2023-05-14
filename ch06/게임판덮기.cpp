#include <stdio.h>

#define BLACK 1
#define WHITE 0
#define Y 0
#define X 1

int C, H, W;

int boardTypes[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},   // r
    {{0, 0}, {0, 1}, {1, 1}},   // ㄱ
    {{0, 0}, {1, 0}, {1, 1}}, // ㄴ
    {{0, 0}, {1, 0}, {1, -1}}, // ㅢ
};


int board[20][20];

int cnt;

void fill_board() {
    // early exit case: cnt num of white
    int white_cnt = 0;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (board[i][j] == WHITE) white_cnt++;
        }
    }
    if (white_cnt % 3 != 0) return;
    // base case: if all filled, cnt++
    int y = -1;
    int x = -1;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (board[i][j] == WHITE) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    if (y == -1 && x == -1) {
        cnt++;
        return;
    }
    // y, x: smallest - top left
    for (int i=0; i<4; i++){
        int dy, dx = 0;
        bool can_place_block = true;
        for (int j=0; j<3; j++) {
            dy = y + boardTypes[i][j][Y];
            dx = x + boardTypes[i][j][X];
            if (board[dy][dx] == BLACK 
                || dy >= H || dy < 0 
                || dx >= W || dx < 0) {
                can_place_block = false;
                break;
            }
        }
        if (can_place_block) {
            for (int j=0; j<3; j++) {
                dy = y + boardTypes[i][j][Y];
                dx = x + boardTypes[i][j][X];
                board[dy][dx] = BLACK;
            }
            fill_board();
            for (int j=0; j<3; j++) {
                dy = y + boardTypes[i][j][Y];
                dx = x + boardTypes[i][j][X];
                board[dy][dx] = WHITE;
            }
        }
    }
}

int main() {
    scanf("%d",&C);
    for (int i=0; i<C; i++) {
        scanf("%d %d", &H, &W);

        // set board
        for (int j=0; j<H; j++) {
            char str[20];
            scanf("%s", str);
            for (int k=0; str[k] != '\0'; k++) {
                board[j][k] = str[k] == '#' ? BLACK : WHITE;
            }
        }

        // fill board
        cnt = 0;
        fill_board();
        printf("%d\n", cnt);
    }
}