#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef enum {
  TK_RESERVED, //記号
  TK_NUM,  //整数トークン
  TK_EOF,  //入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;
//トークン型
struct Token {
  TokenKind kind;
  Token *next;
  int val;
  char *str;
};

//現在着目しているトークン
Token *token;

//エラーを報告するための関数
//printfと同じ引数を取る
void error(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

//次のトークンが期待している記号のときには、トークンを一つ読み進めて
//真を返す。それ以外の場合には偽を返す。
bool consume(char op){
  if(token->kind != TK_RESERVED || token->str[0] != op) {
    return false;
  } else {
    token = token -> next;
    return true;
  }
}

void expect(char op){
  if(token->kind != TK_RESERVED || token->str[0] != op)
  error("expected '%c'", op);
  token = token->next;
}

int expect_number(){
  if(token->kind != TK_NUM){
    error("expected a number");
  }else{
    int val = token -> val;
    token = token -> next;
    return val;
  }
}

bool at_eof(){
  return token->kind == TK_EOF;
}

Token *new_token(TokenKind kind, Token *cur, char *str){
  Token *tok = calloc(1, sizeof(Token));
  tok -> kind = kind;
  tok -> str = str;
  cur -> next = tok;
  return tok;
}

Token *tokenize(char *p) {
  Token head;
  head.next = NULL;
  Token *cur = &head;

  while(*p){
    if(isspace(*p)){
      p++;
      continue;
    }
//記号トークンとしてenumで定義した種別をメモリで割り当てる
    if(*p == '+' || *p == '-'){
      cur = new_token(TK_RESERVED, cur, p++);
      continue;
    }
//数値トークンとしてenumで定義した種別をメモリで割り当てる
    if(isdigit(*p)){
      cur = new_token(TK_NUM, cur, p);
      cur->val = strtol(p, &p, 10);
      continue;
    }
//それ以外の記号トークンは予測できないものとしてエラーを返す
    error("invalid token");
  }

  new_token(TK_EOF, cur, p);
  return head.next;
}

int main(int argc, char **argv){
  if(argc != 2) {
    error("%s: invalid number of argument", argv[0]);
    return 1;
  }

  token = tokenize(argv[1]);

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  printf("  mov rax, %d\n", expect_number());

  while(!at_eof()){
    if(consume('+')) {
      printf("  add rax, %d\n", expect_number());
      continue;
    }
    expect('-');
    printf("  sub rax, %d\n", expect_number());
  }

  printf("  ret\n");
  return 0;
}
