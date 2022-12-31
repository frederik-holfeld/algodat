// by Frederik Holfeld

#include <stdio.h>

#define MAX 10

typedef struct {
  int arr[MAX];
  int front, rear, size;
} Queue;


/******************************************************************************/


int empty(Queue q) {
  if (q.size == 0) return 1;
  return 0;
}

void enqueue(Queue *q, int e) {
  if (q->size >= MAX) {
    printf("Die Queue ist bereits voll!\n");
  } else if (empty(*q) == 1) {
    q->arr[q->rear] = e;
    q->size++;
  } else {
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = e;
    q->size++;
  }
}

int dequeue(Queue *q) {
  if (empty(*q) == 0) {
    // Da der Wert aus dem Array nicht gelöscht werden kann, wird lediglich
    // size geändert. Das Löschen wird jedoch in printQueue() berücksichtigt,
    // da dort nur von front bis rear ausgegeben wird.
    q->size--;
    int tmp = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    return tmp;
  }
  printf("Keine Elemente vorhanden\n");
  return -1;
}

int size(Queue q) {
  return q.size;
}

int front(Queue q) {
  if (empty(q) == 1) {
    printf("Keine Elemente vorhanden\n");
    return -1;
  }
  return q.front;
}

void printQueue(Queue q) {
  printf("\nQueue: ");
  for (int i = q.front; i != q.rear; i = (i + 1) % MAX) {
    printf("%d", q.arr[i]);
  }
  if (empty(q) == 0) printf("%d", q.arr[q.rear]);
  printf("\nFront: %d\n", q.front);
  printf("Rear: %d\n", q.rear);
  printf("Size: %d\n\n", size(q));
}


/******************************************************************************/


int main() {
  Queue queue1 = {
    .front = 0,
    .rear = 0,
    .size = 0
  };

  printQueue(queue1);

for (int i = 0; i < 2; i++) {
  enqueue(&queue1, 1);
  enqueue(&queue1, 2);
  enqueue(&queue1, 7);
  enqueue(&queue1, 0);
  enqueue(&queue1, 3);
  enqueue(&queue1, 7);
  enqueue(&queue1, 4);
  printQueue(queue1);
}

for (int i = 0; i < 8; i++) {
  printf("%d\n", dequeue(&queue1));
}
  return 0;
}
