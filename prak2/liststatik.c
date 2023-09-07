#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l){
    int i;
    for (i=0; i<CAPACITY; i++){
        ELMT(*l,i) = MARK;
    }
}

int listLength(ListStatik l){
    int i = 0;
     while (ELMT(l,i)!=MARK){
        i++;
     }
     return i;
}

IdxType getFirstIdx(ListStatik l){
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
    return listLength(l)-1;
}

boolean isIdxValid(ListStatik l, IdxType i){
    return i>=IDX_MIN && i<CAPACITY;
}

boolean isIdxEff(ListStatik l, IdxType i){
    return i>=0 && i<listLength(l);
}

boolean isEmpty(ListStatik l){
    return ELMT(l,IDX_MIN)==MARK;
}

boolean isFull(ListStatik l){
    return listLength(l)==CAPACITY;
}

void readList(ListStatik *l){
    int n;
    scanf("%d",&n);
    while (n<0 || n>CAPACITY){
        scanf("%d",&n);
    }
    CreateListStatik(l);
    for (int i=0; i<n; i++){
        scanf("%d",&ELMT(*l,i));
    }
}

void printList(ListStatik l){
    int i = 0;
    printf("%s","[");
    while (ELMT(l,i)!=MARK){
        if (i==0){
            printf("%d",ELMT(l,i));
        }
        else {
            printf(",%d",ELMT(l,i));
        }
        i++;
    }
    printf("%s","]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik listBaru;
    CreateListStatik(&listBaru);
    int i;
    int lenList = listLength(l1);
    if (plus){
        for (i=0; i<lenList; i++){
            ELMT(listBaru,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    }
    else {
        for (i=0; i<lenList; i++){
            ELMT(listBaru,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return listBaru;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    int i=0;
    while (i<listLength(l1) && ELMT(l1,i)==ELMT(l2,i)){
        i++;
    }
    return listLength(l1)==listLength(l2) && i==listLength(l1);
}

int indexOf(ListStatik l, ElType val){
    int i = 0;
    boolean found = false;
    while (!found && i<listLength(l)){
        if (ELMT(l,i)==val){
            found = true;
        }
        i++;
    }
    if (isEmpty(l) || i == listLength(l)){
        return IDX_UNDEF;
    }
    else {
        return i-1;
    }
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for (int i=0; i<listLength(l); i++){
        if (ELMT(l,i)>*max){
            *max = ELMT(l,i);
        }
        if (ELMT(l,i)<*min){
            *min = ELMT(l,i);
        } 
    }
}

void insertFirst(ListStatik *l, ElType val){
    for (int i = listLength(*l)-1; i>=0; i--){
        ELMT(*l,i+1) = ELMT(*l,i);
    }
    ELMT(*l,0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    for (int i = listLength(*l)-1; i>=idx; i--){
        ELMT(*l,i+1) = ELMT(*l,i);
    }
    ELMT(*l,idx) = val;
}

void insertLast(ListStatik *l, ElType val){
    ELMT(*l,listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
    *val = ELMT(*l,0);
    for (int i=0; i<listLength(*l);i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    ELMT(*l,listLength(*l)) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    *val = ELMT(*l,idx);
    for (int i=idx; i<listLength(*l); i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
}

void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l,getLastIdx(*l));
    ELMT(*l,listLength(*l)-1) = MARK;
}

void sortList(ListStatik *l, boolean asc){
    if (asc){
        for (int i=0; i<listLength(*l); i++){
            for (int j=i+1; j<listLength(*l); j++){
                if (ELMT(*l,i)>ELMT(*l,j)){
                    int temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            }
        }
    }
    else {
        for (int i=0; i<listLength(*l); i++){
            for (int j=i+1; j<listLength(*l); j++){
                if (ELMT(*l,i)<ELMT(*l,j)){
                    int temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            }
        }
    }
}
