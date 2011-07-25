#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char *City;
  int Temp;
  struct Node *Next;
};

typedef struct Node *Link;
Link Head;
int NodeCount;

// Add a node
int AddNodeAscend(Link);
// initialize list
void CreateList(void);
// delete a node
int DeleteNode(Link);
// handle duplicate inserts
int DuplicateNode(Link, Link);
// free a node's memory
void FreeNode(void);
// show list of nodes
void ShowNodes(void);
// compare two nodes
int NodeCmp(Link, Link);

int NodeCmp(Link a, Link b)
{
  /* returns 1, 0, -1, depending on whether the data in 
   * a is greater than, equal, or less than b.
   */

  /* if temps are unequal, return based on temp */
  if(a->Temp != b->Temp)
    return (a->Temp - b->Temp);

  /* else, return based on city's name */
  return strcmp(a->City, b->City);
}

void FreeNode(Link n)
{
  free(n->City);
  free(n);
}

int DuplicateNode(Link inlist, Link duplicate)
{
  FreeNode(duplicate);
  return 0;
}

int AddNodeAscend(Link to_add)
{
  Link pn, prev, curr;
  struct Node dummy;
  int i;
  pn = (Link)malloc(sizeof(struct Node));
  if(pn == NULL)
    return 0;
  memcpy(pn, to_add, sizeof(struct Node));

  dummy.Next = Head;
  prev = &dummy;
  curr = Head;

  for( ; ; prev = curr, curr = curr->Next)
    {
      if(curr == NULL)
	break;

      i = NodeCmp(pn, curr);
      if(i <= 0)
	break;
    }

  if( curr && i == 0)
    if(DuplicateNode(curr, pn) == 0)
      return 1;

  prev->Next = pn;
  pn->Next = curr;

  Head = dummy.Next;
  return 1;
}

void CreateList(void)
{
  Head = NULL;
  NodeCount = 0;
}

int DeleteNode(Link to_delete)
{
  Link curr, prev;
  int i;

  if(Head = NULL)
    return 0;

  for(prev = NULL, curr = Head; 
      curr != NULL && (i = NodeCmp(to_delete, curr)) > 0;
      prev = curr, curr = curr->Next)
    ;

  if(curr != NULL && i == 0)
