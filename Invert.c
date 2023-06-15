//
// Created by Administrador on 15/6/2023.
//

#include "Invert.h"
#include <stdio.h>
#include <stdlib.h>

Node *newNode(int data) {
    Node * aux = NULL;
    aux = malloc(sizeof(Node));
    if(aux == NULL){
        printf("Error");
        exit (-1);
    }
    aux->data = data;
    aux->next = NULL;
    return aux;
}

Queue *newQueue(){
    Queue * aux = malloc(sizeof(Queue));
    if(aux == NULL){
        printf("Error\n");
        exit (-1);
    }
    aux->tail = NULL;
    aux->head = NULL;
    return aux;
}

Stack *newStack(){
    Stack * aux = NULL;
    aux = malloc(sizeof(Stack));
    if(aux == NULL){
        printf("Error\n");
        exit (-1);
    }
    aux->top = NULL;
    return aux;
}

void enqueue(Queue *queue, Node *nodeQueue) {
    if(queue->head == NULL){
        queue->head = nodeQueue;
        queue->tail = nodeQueue;
    }else{
        queue->tail->next = nodeQueue;
        queue->tail = nodeQueue;
    }
}

Node *dequeue(Queue *queue) {
    Node * nodeOut = queue->head;
    queue->head = queue->head->next;
    return nodeOut;
}

void pile(Node *nodeOut, Stack *stack) {
    if(stack->top == NULL){
        stack->top = nodeOut;
    }else{
        nodeOut->next = stack->top;
        stack->top = nodeOut;
    }
}

Node *unpile(Stack *stack) {
    Node * nodeOut = stack->top;
    stack->top = stack->top->next;
    return nodeOut;
}

void requeue(Node *nodeOut, Queue *queue) {
    if(queue->head == NULL){
        queue->head = nodeOut;
        queue->tail = nodeOut;
    }else{
        queue->tail->next = nodeOut;
        queue->tail = nodeOut;
    }
}

void printQueue(Queue *queue) {
    Node * aux = queue->head;
    printf("\nQueue:\n");
    if(aux == NULL){
        printf("Empty queue\n");
    }else{
        while(aux != NULL){
            printf("%d -> ", aux->data);
            aux = aux->next;
        }
        printf("NULL\n");
    }
}

void printStack(Stack *stack) {
    Node * aux = stack->top;
    if(aux == NULL){
        printf("Empty stack\n");
    }else{
        while(aux != NULL){
            printf("%d\n", aux->data);
            printf("|\n");
            printf("v\n");
            aux = aux->next;
        }
        printf("NULL\n");
    }
}





