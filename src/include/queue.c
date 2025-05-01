#include <stdlib.h>
#include "queue.h"

/**
 * Initialize a new empty queue
 */
Queue* queue_init() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue_is_empty(queue)) {
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

/**
 * Check if a queue is empty
 */
bool queue_is_empty(Queue* queue) {
    if (queue == NULL) {
        return true;
    }
    return queue->size == 0;
}

/**
 * Get the current size of the queue
 */
int queue_size(Queue* queue) {
    if (queue_is_empty(queue)) {
        return 0;
    }
    return queue->size;
}

/**
 * Add an element to the rear of the queue
 */
bool queue_enqueue(Queue* queue, void* data) {
    // Create new node
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        return false;
    }

    new_node->data = data;
    new_node->next = NULL;

    // If queue is empty, set both front and rear to new node
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        // Add new node at the end and update rear
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    
    queue->size++;
    return true;
}

/**
 * Remove an element from the front of the queue
 */
void* queue_dequeue(Queue* queue) {
    if (queue_is_empty(queue) || queue->front == NULL) {
        return NULL;
    }

    // Store the front node and data
    QueueNode* temp = queue->front;
    void* data = temp->data;

    // Move front to next node
    queue->front = queue->front->next;

    // If front becomes NULL, then also update rear
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    queue->size--;
    free(temp);
    return data;
}

/**
 * Peek at the front element without removing it
 */
void* queue_peek(Queue* queue) {
    if (queue_is_empty(queue) || queue->front == NULL) {
        return NULL;
    }
    return queue->front->data;
}

/**
 * Clear all elements from the queue
 */
void queue_clear(Queue* queue) {
    if (queue_is_empty(queue)) {
        return;
    }

    QueueNode* current = queue->front;
    QueueNode* next;

    // Free all nodes and data
    while (current != NULL) {
        next = current->next;

        free(current->data);
        free(current);

        current = next;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

/**
 * Destroy the queue and free all memory
 */
void queue_destroy(Queue* queue) {
    if (queue == NULL) {
        return;
    }

    // Clear all elements first
    queue_clear(queue);
    
    // Free the queue structure itself
    free(queue);
}
