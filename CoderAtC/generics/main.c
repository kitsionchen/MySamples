#include <stdio.h>
#include "generics.h"

typedef struct {
  const char *name;
  int score;
} student_t;

int cmp_student(void *a, void *b)
{
  if(((student_t *a))->score > ((student_t *)b)->score)
    return 1;
  else if(((student_t *)a)->score == ((student_t *)b)->score)
    return 0;
  else 
    return -1;
}


int main(void)
{
  student_t list[4] = {{"Tom", 68}, {"Jerry", 72}, {"Moby", 60}, {"Kirby", 89}};
  student_t *plist[4] = {&list[0], &list[1], &list[2], &list[3]};
  student_t *pmax = max((void **)plist, 4, cmp_student
