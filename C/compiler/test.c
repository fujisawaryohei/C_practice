#include <stdio.h>
int main(void){
  char *p;
  p = "hello";
  printf("%s\n", p);
  printf("%p\n", &p);
  p++;
  printf("%s\n", p);
  printf("%p\n", &p);
}
