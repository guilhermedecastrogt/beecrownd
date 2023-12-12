#include <stdio.h>
#include <stdbool.h>


int ROWS = 6;
int COLS = 7;
char EMPTY = ' ';
char PLAYER1 = 'X';
char PLAYER2 = 'O';

char board[6][7];

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    printf(" LIG4 \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("-|-%c", board[i][j]);
        }
        printf("-|-\n");
    }
    printf("   1   2   3   4   5   6   7\n");
}

bool check_win(char player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j < COLS - 3 && board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
            if (i < ROWS - 3 && board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
            if (i < ROWS - 3 && j < COLS - 3 && board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
            if (i < ROWS - 3 && j > 2 && board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                return true;
            }
        }
    }
    return false;
}

bool place_piece(int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

bool is_draw() {
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == EMPTY) {
            return false;
        }
    }
    return true;
}

int main() {
    char currentPlayer = PLAYER1;
    int col;

    init_board();

    while (true) {
        print_board();
        printf("Jogador %c, digite uma coluna (1-7): ", currentPlayer);
        scanf("%d", &col);
        col--;

        if (col < 0 || col >= COLS || board[0][col] != EMPTY) {
            printf("Coluna invalida.\n");
            continue;
        }

        place_piece(col, currentPlayer);

        if (check_win(currentPlayer)) {
            print_board();
            printf("Jogador %c ganhou!\n", currentPlayer);
            break;
        }

        if (is_draw()) {
            print_board();
            printf("Empate!\n");
            break;
        }

        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
    }

    return 0;
}