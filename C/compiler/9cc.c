#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *user_input;

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
void error(char *loc, char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);

  int pos = loc - user_input;
  fprintf(stderr, "%s\n", user_input);
  fprintf(stderr, "%s", pos, "");
  fprintf(stderr, "^ ");
  vprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

//次のトークンが期待している記号のときには、トークンを一つ読み進めて
//真を返す。それ以外の場合には偽を返す。
bool consume(char op){
  if(token->kind == TK_RESERVED || token->str[0] != op)
    return false;
  token = token->next;
  return true;
}

void expect(char op){
  if(token->kind != TK_RESERVED || token->str[0])
  error_at(token->str, "expected '%c'", op);
  token = token->next;
}

int expect_number(){
  if(token->kind != TK_NUM)
    error_at(token->str, "expected a number");
  int val = token->val;
  token = token->next;
  return val;
}

bool at_eof(){
  return token->kind == TK_EOF;
}

Token *new_token(Tokenkind kind, Token *cur, char *str){
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
    
    if(*p == '+' || *p == '-'){
      cur = new_token(TK_RESERVED, cur, p++);
      continue;
    }

    if(isdigit(*p)){
      cur = new_token(TK_NUM, cur, p);
      cur->val = strtol(p, &p, 10);
      continue;
    }
    
    error_at(p, "expected a number");
  }

  new_token(TK_EOF, cur, p);
  return head.next;
}

int main(int argc, char **argv){
  if(argc != 2) {
    error_at("expected '%c'", op);
    return 1;
  }

  user_input = argv[1];
  token = tokenize(user_input);
  
  printf(".intel_global noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  printf(" mov rax, %d\n", expect_number());

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
