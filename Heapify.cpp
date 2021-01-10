#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void max_heapify(int array[], int index, int heapSize){
  /* add your code here */
    int parent=index;
    int leftchild=2*index+1;
    int rightchild=2*index+2;
    
    while(leftchild <= heapSize && array[leftchild]>array[parent]){
        parent=leftchild;
    }
    while(rightchild<=heapSize && array[rightchild]>array[parent]){
        parent=rightchild;
    }
    if(parent!=index){
        int auxilary=array[parent];
        array[parent]=array[index];
        array[index]=auxilary;
        max_heapify(array,parent,heapSize);
    }
}

int* build_max_heap(int array[], int arraySize){
    int k;
    for (k = arraySize/2; k >= 0; k--) {
        max_heapify(array, k, arraySize);
    }
    return array;
}

void display(int *max_heap, int arraySize){
	int counter;
    for (counter = 0; counter < arraySize; counter++) {
        printf("%d ", max_heap[counter]);
    }
}

int main(){
    int index, arraySize;
	int *array = calloc(MAX, sizeof(int));
    int *max_heap = calloc(MAX, sizeof(int));
    
    scanf("%d", &arraySize);
    
    for (index = 0; index < arraySize; index++) {
        scanf("%d", &array[index]);
    }
    max_heap = build_max_heap(array, arraySize);
    display(max_heap, arraySize);
}