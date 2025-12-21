#include <stdio.h>

int queue[5];
int front =-1, rear =-1;

void enqueue(int val) {
    if ((front==0 && rear==4) || (front==rear + 1)) {
        printf("Queue dolu!\n");
        return;
    }
    
    if (front==-1) front =0;
    rear = (rear + 1) % 5;
    queue[rear] =val;
    printf("Eklendi:%d\n",val);
}

void dequeue() {
    if (front ==-1) {
        printf("Queue bos!\n");
        return;
    }
    
    printf("Cikarildi:%d\n",queue[front]);
    
    if (front ==rear) {
        front =-1;
        rear =-1;
    } else {
        front =(front+1) % 5;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    enqueue(30);
    return 0;
}