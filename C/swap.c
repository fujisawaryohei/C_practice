#include <stdio.h>

void main(void)
{
  int a = 1;
  int* pointer = &a;
  int** pointerOfpointer = &pointer;
  printf("value: %d\npointer: %p\npointer of pointer: %p\n",a,pointer,pointerOfpointer);
}
