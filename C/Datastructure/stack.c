#include <stdio.h>

typedef int STACK_ITEM;
#define STACK_SIZE 30
STACK_ITEM stack[STACK_SIZE];

int sp = 0;
void Init(void)
{
  sp = 0;
}

int IsEmpty(void)
{
  if(sp == 0){
    return 1;
  } else {
    return 0;
  }
}

void Push(STACK_ITEM data)
{
  if(sp < STACK_SIZE){
    stack[sp] = data;
    sp++;
  }
}

STACK_ITEM Pop(void)
{
  if(sp > 0){
    sp--;
    return stack[sp];
  } else {
    return 0;
  }
}

int main(void){
  Init();
  Push(1);
  Push(2);
  Push(3);
  while(!IsEmpty()){
    int data;
    data = Pop();
    printf("%d\n",data);
  }
  printf("¥n");

  return 0;
}
