#include <stdio.h>
int main(int argc, char **argv){
  char *p = "hello";
  char *c = "hello world";
  int pos = p - c;
  printf("%d\n", pos);
  // char *p = argv[1];
  // while(*p){
  //   printf("%s\n", p);
  //   p++;
  // };
}
