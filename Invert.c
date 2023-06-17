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
    if(queue->head == queue->tail){
        queue->head = NULL;
        queue->tail = NULL;
    }else{
        queue->head = queue->head->next;
    }
    nodeOut->next = NULL;
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
    nodeOut->next = NULL;
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
    printf("\nStack:\n");
    if(stack->top == NULL){
        printf("Empty stack\n");
    }else{
        Node * aux = stack->top;
        while(aux != NULL){
            printf("%d\n", aux->data);
            aux = aux->next;
        }
    }
}





