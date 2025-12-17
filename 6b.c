
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at beginning (Stack Push) */
void push(int item) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;
    printf("Element pushed\n");
}

/* Delete from beginning (Stack Pop / Queue Dequeue) */
void pop_dequeue() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Deleted element: %d\n", temp->data);
    head = head->next;
    free(temp);
}

/* Insert at end (Queue Enqueue) */
void enqueue(int item) {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Element enqueued\n");
}

/* Display list */
void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n===== STACK & QUEUE MENU =====\n");
        printf("1. Stack Push\n");
        printf("2. Stack Pop\n");
        printf("3. Queue Enqueue\n");
        printf("4. Queue Dequeue\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop_dequeue();
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 4:
                pop_dequeue();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
