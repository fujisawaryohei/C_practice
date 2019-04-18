
#include <stdio.h>
#define MAXSIZE 30

typedef int LIST_ITEM;
typedef int LIST_INDEX;
#define LIST_TAIL -1

LIST_ITEM list[MAXSIZE];
LIST_INDEX tail;

void Init (void)
{
  tail = 0;
}

LIST_INDEX Top (void)
{
  return 0;
}

LIST_INDEX Next(LIST_INDEX index)
{
  if(index < tail-1) {
    return index+1;
  } else {
    return -1;
  }
}

int Count(void)
{
  return tail;
}

LIST_ITEM Item(LIST_INDEX index)
{
  if((index >= 0) && (index < tail)){
    return list[index];
  } else {
    return 0;
  }
}

void Add(LIST_ITEM value)
{
  if(tail < MAXSIZE) {
    list[tail] = value;
    tail++;
  }
}

void Insert(LIST_INDEX index,LIST_ITEM value)
{
  if((index >= 0) && (index < tail) && (tail < MAXSIZE)){
    int i;
    for(i=tail; i>index; i--){
      list[i] = list[i-1];
    }
    list[index] = value;
    tail++;
  }
}

void Delete(LIST_INDEX index)
{
  if((index >= 0) && (index < tail)){
    int i;
    for(i=index; index>tail-1; i++){
      list[i] = list[i+1];
    }
    tail--;
  }
}

int main(void){
  int p;
  Init();
  Add(1);
  Add(2);
  Add(3);
  Delete(Top());
  Insert(Top(),4);
  printf("count = %d\n", Count());
  for(p=Top(); p!=LIST_TAIL; p=Next(p)) {
    printf(" %d",Item(p));
  }
  printf("\n");
  return 0;
}
