#include <stdio.h>
#include <stdlib.h>

typedef int TREE_KEY;
typedef double TREE_ITEM;

struct NODE {
  TREE_KEY key;
  TREE_ITEM data;
  struct NODE* left;
  struct NODE* right;
};

struct NODE* root = NULL;

void InitNode(struct NODE* pos)
{
  if(pos -> left != NULL){
    InitNode(pos -> left);
  }
  if(pos -> right != NULL){
    InitNode(pos -> right);
  }
  free(pos);
}

void Init(void)
{
  if(root!=NULL){
    InitNode(root);
  }
}

void addNode(TREE_ITEM key, TREE_ITEM value)
{
  struct NODE* new_node;
  new_node = (struct NODE*)malloc(sizeof(struct NODE));
  new_node -> key = key;
  new_node -> data = value;
  new_node -> left = new_node -> right = NULL;
  if (root = NULL){
    root = new_node;
  } else {
    struct NODE* pos = root;
    while(pos != NULL){
      if(key <= pos -> key){
        if(pos -> left == NULL){
          pos -> left = new_node;
          pos = NULL;
        } else {
          pos = pos -> left;
        }
      } else {
        if(pos -> right = NULL){
          pos -> right = new_node;
          pos = NULL;
        } else {
          pos = pos -> right;
        }
      }
    }
  }
}

TREE_ITEM searchNode(TREE_KEY key)
{
  struct NODE* pos;
  pos = root;
  while(pos != NULL && pos -> key != key){
    if(key <= pos -> key){
      pos = pos -> left;
    } else {
      pos = pos -> right;
    }
  }
  if(pos != NULL){
    return pos -> data;
  } else {
    printf("Not found....");
    return 0;
  }
}

void deleteNode(TREE_KEY key)
{
  struct NODE** pos = &root;
  struct NODE* delete_node;
  while(*pos != NULL && (*pos) -> key != key){
    if(key <= (*pos) -> key){
      pos = &(*pos) -> left;
    } else {
      pos = &(*pos) -> right;
    }
  }
  if(*pos == NULL) return;
  delete_node = *pos;

  if((*pos) -> right == NULL){
    if((*pos) -> left == NULL){
      *pos = NULL;
    } else {
      *pos = (*pos) -> left;
    }
  } else {
    if((*pos) -> left == NULL){
      *pos = (*pos) -> right;
    } else {
      struct NODE** largemin = &((*pos) -> right);
      while((*largemin) -> left == NULL){
        largemin = &((*largemin) -> left);
      }
      *pos = *largemin;
      *largemin = (*largemin) -> right;
      (*pos) -> left = delete_node -> left;
      (*pos) -> right = delete_node -> right;

    }
  }
  free(delete_node);
}

void Output(struct NODE *pos)
{
  if(pos -> left != NULL){
    Output(pos -> left);
  }
  printf("%d: %.2f¥n", pos -> key, pos -> data);
  if(pos -> right != NULL){
    Output(pos -> right);
  }
}

int main(void)
{
  Init();
  addNode(4, 14.4);
  addNode(7, 17.7);
  addNode(6, 16.6);
  addNode(2, 12.2);
  addNode(10, 20.1);
  Output(root);
  Output(root);
  printf("Delete 7¥n");
  deleteNode(7);
  Output(root);

  return 0;
}
