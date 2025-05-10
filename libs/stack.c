#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    type value;
    struct Node *prev;
} Node;

void print_stack(Node *head) {
    printf("Stack: ");
    while (head != NULL) {
        printf("%d-> ", head->value);
        head = head->prev;
    }
    printf("NULL\n");
}

struct Node* initialize_stack() {
    return NULL;
}

int is_empty(struct Node *head) {
    return head == NULL;
}

int is_full(struct Node *head) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return 1;
    }
    free(new_node);
    return 0;
}

int push(struct Node **head, type value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return 0;
    }
    new_node->value = value;
    new_node->prev = *head;
    *head = new_node;
    return 1;
}

type pop(struct Node **head) {
    if (is_empty(*head)) {
        return 0;
    }
    Node *temp_node = *head;
    type value = temp_node->value;
    *head = temp_node->prev;
    free(temp_node);
    return value;
}

type peek(struct Node *head) {
    if (is_empty(head)) {
        return 0;
    }
    return head->value;
}

void remove_stack(struct Node **head) {
    Node *prev;
    while (*head != NULL) {
        prev = (*head)->prev;
        free(*head);
        *head = prev;
    }
}
