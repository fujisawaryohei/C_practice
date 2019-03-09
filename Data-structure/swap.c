#include <stdio.h> //スタンダードIO
/*
関数定義
返り値の型　関数名（引数、・・）{
  処置;
  return 返り値;
}

三項演算子
返り値 = (条件) ? A : B;
*/
/* プロトタイプ宣言 */
/* ポインタ：アドレスを格納するための変数 */
/* メモリ（記憶領域）*/
/* 関節演算子 */
// int main(void){
//   int a; /* 変数a分のメモリの確保 */
//   a = 10; /* aのメモリ領域に10を格納 */
//   int *pa; /* ポインタ変数を定義（メモリアドレスを格納することができる変数）メモリアドレスを扱うための特別な変数  */
//   pa = &a; /* アドレス演算子の&をつけると変数aのメモリアドレスを表記できる*/
//   int size = sizeof(pa);
//   printf("%d\n",size);
//   printf("%p\n",&a);
// }
// void f(long a);
// int main(void){
//   long a;
//   a = 10000;
//   f(a);
// }
// void f(long a);
// void f(long a){
//   int size = sizeof(a);
//   printf("%d\n",size);
// }

void swap(int *a, int *b);
int main(void){
  int a = 1;
  int b = 2;
  printf("a:%d,a:%d\n",a,b);
  printf("a:%p,b:%p\n",&a,&b);
  swap(&a,&b);
  printf("a:%d, b:%d\nt",a,b);
  printf("a:%p,b:%p\n",&a,&b);
  return 0;
}
// void f(long *a){
//   *a += 100;
//   int size = sizeof(&a)
//   printf("%ld\n",*a);
//   printf("%p\n",&a);
//   printf("%d\n",*a);
//   // *a += 100;
//   // int size = sizeof(*a);
//   // printf("%d\n",size);
// }

void swap(int *a, int *b){
  int *t;
  *t = *a;
  *a = *b;
  *b = *t;
}
