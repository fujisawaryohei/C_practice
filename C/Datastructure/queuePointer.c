#include <stdio.h>
#include <stdlib.h>

typedef int QUEUE_ITEM;

struct QUEUE {
  int data;
  struct QUEUE* next;
};

struct QUEUE* top = NULL;
struct QUEUE* bottom = NULL;

void Init(void)
{
  if(top != NULL){
    struct QUEUE* delete_item;
    delete_item = top;
    top = top -> next;
    free(delete_item);
  }
}

int isEmpty(void)
{
  if(top == NULL){
    return 1;
  } else {
    return 0;
  }
}

void Enqueue(QUEUE_ITEM value)
{
  struct QUEUE* new_item;
  new_item = (struct QUEUE*)malloc(sizeof(struct QUEUE));
  new_item -> data = value;
  new_item -> next = NULL;
  if(top == NULL){
    top = bottom = new_item;
  } else {
    bottom -> next = new_item;
    bottom = bottom -> next;
  }
}

QUEUE_ITEM Dequeue(void)
{
  QUEUE_ITEM data;
    struct QUEUE* delete_item;
    data = top -> data;
    delete_item = top;
    top = top -> next;
    if(top == NULL){
      bottom = NULL;
    }
    free(delete_item);
    return data;
}

int main(void){
  Init();
  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  while(isEmpty() == 0){
    int data;
    data = Dequeue();
    printf("%d\n",data);
  }
  return 0;
}
