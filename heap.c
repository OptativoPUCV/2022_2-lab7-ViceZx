#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->size == 0){
    return NULL;
  }else{
    return pq->heapArray[0].data;
  }
}



void heap_push(Heap* pq, void* data, int priority){
   if (pq->size == pq->capac){
    pq->capac = (pq->capac*2)+ 1;
    pq->heapArray= realloc(pq->heapArray, pq->capac*sizeof(heapElem));
  }
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  heapElem* aux = (heapElem*) malloc (sizeof(heapElem));
  int x_size= pq->size;
  int xd_size = ((pq->size-1)/2);
  while (x_size > 0){
    if (pq->heapArray[x_size].priority > pq->heapArray[xd_size].priority){
      *aux= pq->heapArray[xd_size];
      pq->heapArray[xd_size]= pq->heapArray[x_size];
      pq->heapArray[x_size]= *aux;
    }
    x_size= xd_size;
    xd_size= (x_size-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
	Heap* new = (Heap*)malloc(sizeof(Heap));
  new->size = 0;
  new->capac = 3;
  new->heapArray = (heapElem*)malloc(3*sizeof(heapElem));
  return new;
}
