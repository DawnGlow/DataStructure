#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

int main(void) {
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;
    Node *newnode = NULL;
    int buffer;
    head = (Node*)malloc(sizeof(Node));
    tail = head;
    while (1) {
        printf("Enter number : ");
        scanf("%d", &buffer);
        if (buffer < 1) {
            break;
        }
        // 더미노드를 생성해서 head를 가리키지 말고 head에 더미노드 생성
        // if (head == NULL) {
        //     newnode = (Node*)malloc(sizeof(Node)); // dummy node creation
        //     newnode->next = NULL;
        //     head = newnode;
        //     tail = newnode;
        // }
        newnode = (Node*)malloc(sizeof(Node));
        newnode->data = buffer;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    printf("\n");
    /* print data */
    printf("printing all data\n");
    if (head == NULL) {
        printf("Data doesn't exist");
    }
    else {
        cur = head->next;
        do {
            printf("%d ", cur->data);
            cur = cur->next;
        } while (cur != NULL);
    }
    printf("\n");
    /*** releasing memory ***/
    if (head == NULL) {
        return 0; // because data doesn't exist, exit program
    }
    else {
        cur = head->next;
        Node *temp = NULL;
        do {
            temp = cur->next;
            free(cur);
            printf("releasing data\n");
            cur = temp;
        } while (cur != NULL);
    }
    return 0;
}