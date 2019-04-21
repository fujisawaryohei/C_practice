#include <stdio.h>

typedef int QUEUE_ITEM;

#define QUEUE_SIZE 30

QUEUE_ITEM queue[QUEUE_SIZE];

int queue_end = 0;

void Init(void)
{
  queue_end = 0;
}

int isEmpty(void)
{
  if(queue_end == 0){
    return 1;
  } else {
    return 0;
  }
}

void Enqueue(QUEUE_ITEM value)
{
  if(queue_end < QUEUE_SIZE){
    queue[queue_end] = value;
    queue_end++;
  }
}

int Dequeue(void){
  if(queue_end > 0){
    int i;
    QUEUE_ITEM data;
    data = queue[0];
    for(i=0;i<queue_end-1;i++){
      queue[i] = queue[i+1];
    }
    queue_end--;
    return data;
  } else {
    return 0;
  }
}

int main(void)
{
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
