#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik list1;
    readList(&list1);
    printList(list1);


    printf("%d\n", listLength(list1));
    printf("getFirstIdx : %d\n", getFirstIdx(list1));
    printf("getLastIdx : %d\n", getLastIdx(list1));

    printf("isIdxValid : %d\n", isIdxValid(list1,5));
    printf("isIdxEff : %d\n", isIdxEff(list1,2));

    printf("isEmpty : %d\n", isEmpty(list1));
    printf("isFull : %d\n", isFull(list1));

    ListStatik list2;
    readList(&list2);
    printList(list2);

    printList(plusMinusList(list1,list2,1));
    printf("isEqual : %d\n",isListEqual(list1,list2));
    printf("indexOf : %d\n", indexOf(list1,2));

    ElType gmax,gmin;
    extremeValues(list1,&gmax,&gmin);
    printf("gmax:%d dan gmin:%d\n", gmax,gmin);

    insertFirst(&list1,55);
    printList(list1);
    insertAt(&list1,56,3);
    printList(list1);
    insertLast(&list1,57);
    printList(list1);

    ElType delVar;
    deleteFirst(&list1,&delVar);
    printf("delVar : %d ",delVar);
    printList(list1);

    deleteAt(&list1,&delVar,2);
    printf("delVar : %d ",delVar);
    printList(list1);

    deleteLast(&list1,&delVar);
    printf("delVar : %d ",delVar);
    printList(list1);
    return 0;
}