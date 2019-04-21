#include <stdio.h>
#include <stdlib.h>

typedef int STACK_ITEM;

struct STACK {
  STACK_ITEM data;
  struct STACK* next;
};

struct STACK* sp = NULL;

void Init(void)
{
  while(sp != NULL){
    struct STACK* delete_item = sp;
    sp = sp -> next;
    free(delete_item);
  }
}

int isEmpty(void)
{
  if(sp == NULL){
    return 0;
  } else {
    return 1;
  }
}

void Push(STACK_ITEM value)
{
  struct STACK* new_item;
  new_item = (struct STACK*)malloc(sizeof(struct STACK));
  new_item -> data = value;
  new_item -> next = sp;
  sp = new_item;
}

STACK_ITEM Pop(void)
{
  STACK_ITEM data;
  if(sp != NULL){
    struct STACK* delete_item;
    data = sp -> data;
    delete_item = sp;
    sp = sp -> next;
    free(delete_item);
  } else {
    data = 0;
  }
  return data;
}

int main(void)
{
  Init();
  Push(1);
  Push(2);
  Push(3);
  while(isEmpty() == 1){
    int data;
    data =Pop();
    printf("%d\n",data);
  }
}
