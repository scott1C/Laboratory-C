#ifndef QUEUE_H
#define QUEUE_H

#include "warehouse.h"

typedef struct QNode
{
    WarehouseRegistry data;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front, *rear;
} Queue;

void initializeQueue(Queue *queue);
void enqueue(Queue *queue, WarehouseRegistry data);
WarehouseRegistry dequeue(Queue *queue);
int isEmptyQueue(Queue *queue);
void freeQueue(Queue *queue);

#endif
