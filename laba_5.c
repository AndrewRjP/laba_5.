#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define K 35


typedef struct node
{
    int val;
    struct node  *prev, *next;
} node;

int main(void)
{
    node *head = NULL;
    node *current = head;
    
    for (int i = 0; i < 20; i++)
    {
        node *el;
        el = malloc(sizeof(node));
        el->val = i;
        if (head == NULL) 
        {
            head = el; 
            head->next = NULL; 
            head->prev = NULL;
            current = head;
        }
        else
        {
            current->next = el;
            el->prev = current;
            current = el;
            current->next = NULL;
        }
     }
     
   
   current->next = head;
   head->prev = current;
   for (int i = 0; i < K; i++) current = current->next;
   
   node *cur = current;
   do
   {
        printf("%d ", cur->val);
        cur = cur->prev;
   } while (cur != current);
   printf("\n");
   
   cur = current;
   while (cur-> next != current)
   {
        if (cur->val % 5 == 0)
        {   
            node *el = malloc(sizeof(node));
            el->val = 0;
            el->next = cur->next;
            el->prev = cur;
            cur->next = el;
            cur = cur->next->next;
            cur->prev = el;
            cur = el; 
        }
        cur = cur->next;
   } 
   
   cur = current;
   do
   {
        printf("%d ", cur->val);
        cur = cur->next;
   } while (cur != current);
   printf("\n");
  
return 0;
}

