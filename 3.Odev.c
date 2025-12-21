#include <stdio.h>

void hanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Disk 1 tasindi: %c -> %c\n", source, dest);
        return;
    }
    
    hanoi(n - 1, source, aux, dest);
    printf("Disk %d tasindi: %c -> %c\n", n, source, dest);
    hanoi(n - 1, aux, dest, source);
}

int main() {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}