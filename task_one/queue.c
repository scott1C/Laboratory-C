#include <stdlib.h>
#include "queue.h"

void initializeQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
}

void enqueue(Queue *queue, WarehouseRegistry data)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

WarehouseRegistry dequeue(Queue *queue)
{
    if (isEmptyQueue(queue))
    {
        WarehouseRegistry empty = {0};
        return empty;
    }
    QNode *temp = queue->front;
    WarehouseRegistry dequeuedData = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return dequeuedData;
}

int isEmptyQueue(Queue *queue)
{
    return queue->front == NULL;
}

void freeQueue(Queue *queue)
{
    while (!isEmptyQueue(queue))
    {
        dequeue(queue);
    }
}
