#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

char **board;

typedef struct MemList {
    void *ptr;
    struct MemList *next;
} MemList;

MemList *head = NULL;

void* custom_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        perror("Failed to allocate memory.");
        exit(EXIT_FAILURE);
    }

    MemList *newEntry = malloc(sizeof(MemList));
    if (!newEntry) {
        perror("Failed to allocate memory for memlist.");
        free(ptr);
        exit(EXIT_FAILURE);
    }

    newEntry->ptr = ptr;
    newEntry->next = head;
    head = newEntry;

    return ptr;
}

void custom_free_all() {
    while (head) {
        free(head->ptr);
        MemList *temp = head;
        head = head->next;
        free(temp);
    }
}

void init_board() {
    board = custom_malloc(ROWS * sizeof(char *));
    for (int i = 0; i < ROWS; i++) {
        board[i] = custom_malloc(COLS * sizeof(char));
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
    // Horizontal, vertical, and diagonal checks
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

    custom_free_all();

    return 0;
}
