#include <stdio.h>


struct Element {
    int row;
    int col;
    int value;
};

int main() {
    struct Element matrix[3];

    matrix[0].row = 0;
    matrix[0].col = 2;
    matrix[0].value = 5;

    matrix[1].row = 1;
    matrix[1].col = 4;
    matrix[1].value = 9;

    matrix[2].row = 3;
    matrix[2].col = 3;
    matrix[2].value = 6;

    printf("Row\tCol\tValue\n");
    for(int i = 0; i < 3; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }

    return 0;
}
