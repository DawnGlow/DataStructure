#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
void ListInit(List *plist) {
    plist->tail = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (plist->tail == NULL) {
        newNode->next = newNode;
    }
    else {
        newNode->next = (plist->tail)->next;
        (plist->tail->next) = newNode;
    }
    plist->tail = newNode;
    (plist->numOfData)++;
}

void LInsertFront(List *plist, Data data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (plist->tail == NULL) {
        newNode->next = newNode;
        plist->tail = newNode;
    }
    else {
        newNode->next = (plist->tail)->next;
        (plist->tail->next) = newNode;
    }
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata) {
    if (plist->tail == NULL) {
        return 0;
    }
    else {
        plist->before = plist->tail;
        plist->cur = (plist->tail)->next;
        *pdata = (plist->cur)->data;
        return 1;
    }
}

int LNext(List *plist, Data *pdata) {
    if (plist->tail == NULL) {
        return 0;
    }
    else {
        plist->before = plist->cur;
        plist->cur = (plist->cur)->next;
        *pdata = (plist->cur)->data;
        return 1;
    }
}

// 틀린 이유 : tail이 삭제되는 경우 tail을 옮겨야 하는 것을 고려하지 않았음
Data LRemove(List *plist) {
    Data result = (plist->cur)->data;
    plist->before->next = plist->cur->next;
    if (plist->cur == plist->tail) { // 꼬리인지 확인
        if (plist->tail == plist->tail->next) { // 마지막 노드라면
            plist->tail = NULL;
        }
        else { // 마지막 노드가 아니라면
            plist->tail = plist->before; // 꼬리를 한칸 앞을 가리키게 이동
        }
    }
    free(plist->cur);
    plist->cur = plist->before;
    (plist->numOfData)--;
    return result;
}

int LCount(List *plist) {
    return plist->numOfData;
}