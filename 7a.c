#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

/* Create doubly linked list */
void create() {
    int item;
    struct node *newnode, *temp;

    printf("Enter elements (-999 to stop): ");
    scanf("%d", &item);

    while (item != -999) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = item;
        newnode->prev = newnode->next = NULL;

        if (start == NULL) {
            start = newnode;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
        scanf("%d", &item);
    }
}

/* Insert a node to the left of a given value */
void insert_left() {
    int value, key;
    struct node *temp, *newnode;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter key value (insert to its left): ");
    scanf("%d", &key);

    temp = start;
    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = value;
    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        start = newnode;

    temp->prev = newnode;

    printf("Node inserted successfully\n");
}

/* Delete a node based on a specific value */
void delete_value() {
    int key;
    struct node *temp;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = start;
    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted element: %d\n", temp->info);
    free(temp);
}

/* Display the list */
void display() {
    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Create List\n");
        printf("2. Insert Left of a Node\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_left(); break;
            case 3: delete_value(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
