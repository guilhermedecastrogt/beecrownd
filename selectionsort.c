#include <stdio.h>
#include <string.h>

int MAX_STUDENTS = 100;
int MAX_NAME_LENGTH = 50;

void selectionSort(char arr[MAX_STUDENTS][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        char temp[MAX_NAME_LENGTH];
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
    }
}

int main() {
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i]);
    }
    selectionSort(students, n);
    printf("\nSorted list of names: \n");
    for (int i = 0; i < n; i++)
        printf("%s\n", students[i]);
    return 0;
}