#include <stdio.h>

int main() {
    int adjMatrix[5][5];


    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            adjMatrix[i][j] =0;

    adjMatrix[0][1] =1;
    adjMatrix[1][3] =1;
    adjMatrix[2][1] =1;
    adjMatrix[4][2] =1;

    printf("0 1 2 3 4\n");
    for(int i=0; i<5; i++) {
        printf("%d ", i);
        for(int j=0;j<5;j++) {
            printf("%d ",adjMatrix[i][j]);
      }
        printf("\n");
 }
    return 0;
 }
