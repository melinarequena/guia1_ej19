//
// Created by Administrador on 15/6/2023.
//

#ifndef GUIA1_EJ19_INVERT_H
#define GUIA1_EJ19_INVERT_H

typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct queue{
    Node * tail;
    Node * head;
}Queue;

typedef struct stack{
    Node * top;
}Stack;

Node * newNode(int data);
Queue * newQueue();
Stack * newStack();

void enqueue(Queue * queue, Node * nodeQueue);
Node * dequeue(Queue * queue);
void pile(Node * nodeOut, Stack * stack);
Node * unpile(Stack * stack);
void requeue(Node * unpile, Queue * queue);
void printQueue(Queue * queue);
void printStack(Stack * stack);


#endif //GUIA1_EJ19_INVERT_H
