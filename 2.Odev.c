#include <stdio.h>

void hanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Disk1: %c -> %c\n",source,dest);
        return;
    }
    
  hanoi(n - 1, source, aux, dest);
    
 printf("Disk %d: %c -> %c\n", n, source, dest);
  hanoi(n - 1, aux, dest, source);
}

int main() {
    int n = 3;
 hanoi(n, 'A', 'C', 'B');
    return 0;
}
