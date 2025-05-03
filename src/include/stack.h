/**
 * @file stack.h
 * @brief Generic stack implementation using void pointers
 * 
 * This header defines a generic stack data structure in C that can store
 * elements of any data type by using void pointers. The user is responsible
 * for proper memory management of the stored data.
 */

 #ifndef STACK_H
 #define STACK_H
 
 #include <stdbool.h>
 
 /**
  * @brief Structure representing a node in the stack
  * 
  * Each node contains a pointer to data and a pointer to the next node.
  * The data is stored as a void pointer to allow any type.
  */
 typedef struct StackNode {
     void* data;                  /* Pointer to the actual data (can be any type) */
     struct StackNode* next;      /* Pointer to the next node in the stack */
 } StackNode;
 
 /**
  * @brief Structure representing the stack itself
  * 
  * The stack contains a pointer to the top node and a count of elements.
  */
 typedef struct {
     StackNode* top;              /* Pointer to the top node of the stack */
     int size;                    /* Current number of elements in the stack */
 } Stack;
 
 /**
  * @brief Initialize a new empty stack
  * 
  * @return Pointer to the newly created stack or NULL on allocation failure
  */
 Stack* stack_create(void);
 
 /**
  * @brief Check if the stack is empty
  * 
  * @param stack Pointer to the stack
  * @return true if the stack is empty, false otherwise
  */
 bool stack_is_empty(const Stack* stack);
 
 /**
  * @brief Get the current size of the stack
  * 
  * @param stack Pointer to the stack
  * @return Number of elements in the stack
  */
 int stack_size(const Stack* stack);
 
 /**
  * @brief Push an element onto the stack
  * 
  * @param stack Pointer to the stack
  * @param data Pointer to the data to be pushed
  * @return true if the push operation was successful, false otherwise
  * 
  * Note: The stack stores a pointer to the data, not a copy.
  * The caller retains ownership of the data and is responsible
  * for ensuring it remains valid while in the stack.
  */
 bool stack_push(Stack* stack, void* data);
 
 /**
  * @brief Pop an element from the stack
  * 
  * @param stack Pointer to the stack
  * @return Pointer to the data that was popped, or NULL if the stack is empty
  * 
  * Note: The caller is responsible for freeing the memory of the returned data
  * if it was dynamically allocated.
  */
 void* stack_pop(Stack* stack);
 
 /**
  * @brief Peek at the top element without removing it
  * 
  * @param stack Pointer to the stack
  * @return Pointer to the data at the top of the stack, or NULL if the stack is empty
  */
 void* stack_peek(const Stack* stack);
 
 /**
  * @brief Clear all elements from the stack
  * 
  * @param stack Pointer to the stack
  * @param free_data Function pointer to free data (can be NULL if not needed)
  * 
  * If free_data is provided, it will be called on each data item to free it.
  * If not provided (NULL), only the nodes are freed but not the data they point to.
  */
 void stack_clear(Stack* stack, void (*free_data)(void*));
 
 /**
  * @brief Destroy the stack and free all allocated memory
  * 
  * @param stack Pointer to the stack
  * @param free_data Function pointer to free data (can be NULL if not needed)
  * 
  * Similar to stack_clear, but also frees the stack structure itself.
  */
 void stack_destroy(Stack* stack, void (*free_data)(void*));
 
 #endif /* STACK_H */