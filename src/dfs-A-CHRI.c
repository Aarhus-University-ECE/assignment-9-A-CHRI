/*
 * Search an expression using DFS.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */
#include "dfs.h"

void DFT(node *root)
{
  /* Initiate the stack */
  stack *top = (stack*)malloc(sizeof(stack));
  top = NULL;

  /* Push the root node to the stack */
  push(top, root);  

  /* While the stack is not empty:*/
  while(top != NULL) {
    stack *left = top->next->node->lchild;
    stack *right = top->next->node->rchild;

    /* Pop and visit the top node in the stack */
    top->node->visited = true;
    pop(top);
    
    /* Add the children to the stack */
    push(top, right);
    push(top, left);
  }

}

node *make_node(int num, node *left, node *right)
{
  /* Allocate memory for the new node */
  node *new = (node *)malloc(sizeof(node));

  /* Set the values for the new node */
  new->num = num;
  new->lchild = left;
  new->rchild = right;
  new->visited = false;

  return 0;
}

void free_node(node *p)
{
  free(p);
}

void print_node(node *p)
{

  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d", p->num);
}

void print_tree(node *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node)
{
  /* Allocate memory for the new stack element */
  stack *new = (stack *)malloc(sizeof(stack));

  /* Add the stack element to top of the stack */
  new->next = topp;
  new->node = node;

  return new;
}

bool isEmpty(stack *topp)
{
  return topp == NULL;
}

node *top(stack *topp)
{
  return topp->node;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp)
{
  /* Grab the top element*/
  stack *t = topp;
  printf("%d ", t->node->num);
  free(t);

  /* Detach the top element from the stack */
  topp = topp->next;

  /* Return the stack */
  return topp;
}

void print_stack(stack *topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}
