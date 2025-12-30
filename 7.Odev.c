#include <stdio.h>
#define CAPACITY 100 

int array[CAPACITY];
int size = 0; 

void printArray() {
    printf("Dizi: ");
    for(int i = 0; i < size; i++) {
         printf("%d ", array[i]);
    }
    printf("\n");
}

void insert(int index, int value) {
    if (size >= CAPACITY) {
        printf("Dizi dolu, ekleme yapilamaz.\n");
     return;
    }
    if (index < 0 || index > size) {
        printf("Gecersiz indeks.\n");
     return;
    }

  
    for (int i = size; i > index; i--) {
        array[i] = array[i-1];
    }
      array[index] = value;
     size++; 
}


void deleteElement(int index) {
    if (index < 0 || index >= size) {
        printf("Gecersiz indeks, silme yapilamaz.\n");
        return;
    }

     for (int i = index; i < size - 1; i++) {
        array[i] = array[i+1];
    }
    
    size--; 
}

int main() {
   
    insert(0, 10);
    insert(1, 20);
    insert(2, 30);
    insert(3, 40);
    printArray(); 
    
    printf("\nIndex 2'ye 25 ekleniyor.\n");
    insert(2, 25);
    printArray(); 
    
     printf("\nIndex 1 siliniyor.\n");
     deleteElement(1);
     printArray();
     return 0;
}
