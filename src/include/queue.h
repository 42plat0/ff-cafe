#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/**
 * @brief Structure to represent a node in the queue
 */
typedef struct QueueNode {
    void* data;
    struct QueueNode* next;
} QueueNode;

/**
 * @brief Structure to represent a Queue
 */
typedef struct Queue {
    QueueNode* front;    // Points to front of queue where elements are dequeued
    QueueNode* rear;     // Points to rear of queue where elements are enqueued
    int size;            // Current number of elements in the queue
} Queue;

/**
 * @brief Initialize a new empty queue
 * @return Pointer to newly created Queue or NULL on failure
 */
Queue* queue_init();

/**
 * @brief Check if a queue is empty
 * @param queue Pointer to the Queue
 * @return true if empty, false otherwise
 */
bool queue_is_empty(Queue* queue);

/**
 * @brief Get the current size of the queue
 * @param queue Pointer to the Queue
 * @return Number of elements in the queue
 */
int queue_size(Queue* queue);

/**
 * @brief Add an element to the rear of the queue
 * @param queue Pointer to the Queue
 * @param data Pointer to the data to enqueue
 * @return true on success, false on failure
 */
bool queue_enqueue(Queue* queue, void* data);

/**
 * @brief Remove an element from the front of the queue
 * @param queue Pointer to the Queue
 * @return Pointer to the dequeued data or NULL if queue is empty
 */
void* queue_dequeue(Queue* queue);

/**
 * @brief Peek at the front element without removing it
 * @param queue Pointer to the Queue
 * @return Pointer to the front data or NULL if queue is empty
 */
void* queue_peek(Queue* queue);

/**
 * @brief Clear all elements from the queue
 * @param queue Pointer to the Queue
 */
void queue_clear(Queue* queue);

/**
 * @brief Destroy the queue and free all memory
 * @param queue Pointer to the Queue
 */
void queue_destroy(Queue* queue);

#endif /* QUEUE_H */
