#include <stdio.h>
#include <stdlib.h>
struct LIST {
  int data;
  struct LIST* next;
};
struct LIST* top = NULL;

typedef int LIST_ITEM;
typedef struct LIST* LIST_INDEX;
#define LIST_TAIL NULL

void Init(void)
{
  while(top != LIST_TAIL){
    struct LIST* delete_index = top;
    top = top -> next;
    free(delete_index);
  }
}

LIST_INDEX Top(void)
{
  return top;
}

LIST_INDEX Next(LIST_INDEX index)
{
  if(index != LIST_TAIL){
    return index -> next;
  } else {
    return LIST_TAIL;
  }
}

int Count(void)
{
  int cnt = 0;
  struct LIST* p;
  for(p=top; p!=LIST_TAIL; p=p -> next){
    cnt++;
  }
  return cnt;
}

LIST_ITEM Item(LIST_INDEX index)
{
  if(index != LIST_TAIL){
    return index -> data;
  } else {
    return 0;
  }
}

void Add(LIST_ITEM value){
  if(top == LIST_TAIL){
    top = (struct LIST*)malloc(sizeof(struct LIST));
    top -> data = value;
    top -> next = LIST_TAIL;
  } else {
    struct LIST* p = top;
    while(p -> next != LIST_TAIL){
      p = p -> next;
    }
    p -> next = (struct LIST*)malloc(sizeof(struct LIST));
    p -> next -> data = value;
    p -> next -> next = LIST_TAIL;
  }
}

void Insert(LIST_INDEX index,LIST_ITEM value){
  if(index == top){
    struct LIST* new_item;
    new_item = (struct LIST*)malloc(sizeof(struct LIST));
    new_item -> data = value;
    new_item -> next = top;
    top = new_item;
  } else if(index != LIST_TAIL){
    struct LIST* p = top;
    struct LIST* new_item;
    while(index != p->next){
      p = Next(p);
    }
    new_item = (struct LIST*)malloc(sizeof(struct LIST));
    new_item -> data = value;
    new_item -> next = p -> next;
    p -> next = new_item;
  }
}

void Delete(LIST_INDEX index){
  if(index != LIST_TAIL){
    if(index == top){
      top = top -> next;
      free(index);
    } else {
      struct LIST* p = top;
      while(index != p -> next){
        p = p -> next;
      }
      p -> next = p -> next -> next;
      free(index);
    }
  }
}

int main(void){
  LIST_INDEX p;
  Init();
  Add(1);
  Add(2);
  Add(3);
  Delete(Top());
  Insert(Top(),4);
  printf("count=%d\n",Count());
}
