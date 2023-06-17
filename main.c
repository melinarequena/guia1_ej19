#include <stdio.h>
#include "Invert.h"

int main() {
    Queue * queue = newQueue();
    Stack * stack = newStack();

    enqueue(queue, newNode(1));
    enqueue(queue, newNode(2));
    enqueue(queue, newNode(3));


    printQueue(queue);

    pile(dequeue(queue), stack);
    pile(dequeue(queue), stack);
    pile(dequeue(queue), stack);

    printStack(stack);

    requeue(unpile(stack), queue);
    requeue(unpile(stack), queue);
    requeue(unpile(stack), queue);

    printQueue(queue);


    return 0;
}
