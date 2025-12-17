#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL, *head2 = NULL;

/* Create a linked list */
struct Node* create() {
    int item;
    struct Node *head = NULL, *temp, *newNode;

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
    return head;
}

/* Display list */
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Sort linked list */
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL) return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

/* Reverse linked list */
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Concatenate two lists */
struct Node* concatenate(struct Node *head1, struct Node *head2) {
    struct Node *temp;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SLL MENU =====\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Sort List 1\n");
        printf("5. Reverse List 1\n");
        printf("6. Concatenate List 1 & List 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head1 = create(); break;
            case 2: head2 = create(); break;
            case 3: display(head1); break;
            case 4:
                sortList(head1);
                printf("List sorted\n");
                break;
            case 5:
                head1 = reverseList(head1);
                printf("List reversed\n");
                break;
            case 6:
                head1 = concatenate(head1, head2);
                printf("Lists concatenated\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
