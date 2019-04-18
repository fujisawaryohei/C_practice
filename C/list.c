
#include <stdio.h>
#define MAXSIZE 30

int list[MAXSIZE];
int tail;

void Init (void)
{
  tail = 0;
}

int Top (void)
{
  return 0;
}

int Next(int index)
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

int Item(int index)
{
  if((index >= 0) && (index < tail)){
    return list[index];
  } else {
    return 0;
  }
}

void Add(int value)
{
  if(tail < MAXSIZE) {
    list[tail] = value;
    tail++;
  }
}

void Insert(int index,int value)
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

void Delete(int index)
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
  for(p=Top(); p!=-1; p=Next(p)) {
    printf(" %d",Item(p));
  }
  printf("\n");
  return 0;
}
