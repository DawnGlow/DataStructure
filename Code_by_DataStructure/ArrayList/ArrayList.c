#include "ArrayList.h"

#include <stdio.h>

void ListInit(List *plist) {
    plist->numOfData = 0;
    plist->curPosition = -1;
}
void LInsert(List *plist, LData data) {
    if (plist->numOfData < LIST_LEN) {
        plist->arr[plist->curPosition + 1] = data;
        (plist->numOfData)++;
        (plist->curPosition)++;
    }
}
int LFirst(List *plist, LData *pdata) {
    if (plist->numOfData != 0) {
        *pdata = plist->arr[0];
        plist->curPosition = 0;
        return 1;
    } else
        return 0;
}

int LNext(List *plist, LData *pdata) {
    plist->curPosition++;
    if (plist->curPosition < plist->numOfData) {
        *pdata = plist->arr[plist->curPosition];
        return 1;
    } else
        return 0;
}

LData LRemove(List *plist) {
    if (plist->curPosition >= 0) {
        int result = plist->arr[plist->curPosition];
        plist->numOfData -= 1;
        /*
        1, 2, 3 // numofdata 3
        2, 3 // numof data 2
        */
        for (int i = plist->curPosition; i < plist->numOfData; i++) {
            plist->arr[i] = plist->arr[i + 1];
        }
        plist->arr[plist->numOfData] = 0;
        plist->curPosition -= 1;
        return result;
    } else {
        printf("can't remove data anymore\n");
        return 0;
    }
}
int LCount(List *plist) {
    return plist->numOfData;
}
