#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}


void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("\nEleman %d basariyla kuyruga eklendi.\n", value);
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Kuyruk bos. Cikarma yapilmaz.\n");
        return;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("\nEleman %d basaiyla cikarildi.\n", temp->data);
    free(temp);
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Kuyruk bos.\n");
        return;
    }
    Node* temp = queue->front;
    printf("Kuyruktaki elemanlar: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\nLutfen asagadaki islemlerden birine seciniz :\n");
        printf("1. Eklenme\n");
        printf("2. Silme\n");
        printf("3. Goruntuleme\n");
        printf("4. Cikis\n\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEklemek istediginiz degeri giriniz: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Programdan cikiliyor.\n");
                break;
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }
    } while (choice != 4);

    return 0;
}

