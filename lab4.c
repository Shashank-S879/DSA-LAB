#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int item;
    struct Node *temp, *newNode;

    printf("Enter elements (-999 to stop): ");
    scanf("%d", &item);

    while (item != -999) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = item;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        scanf("%d", &item);
    }
}

void insert_begin() {
    int item;
    struct Node *newNode;

    printf("Enter element to insert at beginning: ");
    scanf("%d", &item);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void insert_pos() {
    int item, pos, i;
    struct Node *newNode, *temp;

    printf("Enter element and position: ");
    scanf("%d %d", &item, &pos);

    if (pos == 1) {
        insert_begin();
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_end() {
    int item;
    struct Node *newNode, *temp;

    printf("Enter element to insert at end: ");
    scanf("%d", &item);

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
}

void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_begin(); break;
            case 3: insert_pos(); break;
            case 4: insert_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

