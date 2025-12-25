#include <stdio.h>

struct Eleman {
    int satir;
    int sutun;
    int deger;
  };

int main() {
    int normalMatris[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    struct Eleman sparse[20];
    int k= 0; 
  for(int i=0; i<4; i++) {
        for(int j=0; j<5;  j++) {
            if(normalMatris[i][j] !=0) {
                sparse[k].satir = i;
                sparse[k].sutun = j;
                sparse[k].deger =normalMatris[i][j];
                k++;
             }
        }
      }

    
    printf("Satir\tSutun\tDeger\n");
    for(int i=0;i<k;i++) {
        printf("%d\t%d\t%d\n", sparse[i].satir, sparse[i].sutun, sparse[i].deger);
    }

    return 0;
}
