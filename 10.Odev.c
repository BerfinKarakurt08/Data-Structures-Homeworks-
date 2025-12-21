#include <stdio.h>

int heap[100];
int n=0;

void swap(int*a, int*b) {
    int temp = *a;
    *a=*b;
    *b=temp;

}

void heapify(int i) {
    int largest =i;
    int left =2*i + 1;
    int right =2*i + 2;

    if (left<n && heap[left]>heap[largest])
        largest = left;

    if (right<n && heap[right] >heap[largest])
        largest = right;

    if (largest!=i) {
        swap(&heap[i],&heap[largest]);
        heapify(largest);
     }
}

void insert(int val) {
    heap[n] = val;
    n++;
    int i=n-1;


    while (i!=0 && heap[(i-1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i =(i-1)/2;
      }
   }

void deleteMax() {
    if(n<=0) return;

    heap[0]=heap[n-1];
    n--;
    heapify(0);
 }

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);

    printf("Heap:");
    for(int i=0;i<n;i++) printf("%d ",heap[i]);
    printf("\n");

    deleteMax();
    printf("Son durum: ");
    for(int i=0;i<n;i++) printf("%d ",heap[i]);
     return 0;
}
