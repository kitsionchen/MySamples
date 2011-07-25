#include <stdio.h>
#include <assert.h>

#define LEN 8
int a[LEN] = {1, 2, 2, 2, 5, 6, 8, 9};

int is_sorted(void)
{
  int i;
  for(i = 1; i < LEN; i++)
    if(a[i-1] > a[i])
      return 0;
  return 1;
}

int mustbe(int start, int end, int number)
{
  int i;
  for(i = 0; i < start; i++)
    if(a[i] == number)
      return 0;

  for(i = end+1; i < LEN; i++)
    if(a[i] == number)
      return 0;

  return 1;
}

int contains(int n)
{
  int i;
  for(i = 0; i < LEN; i++)
    if(a[i] == n)
      return 1;
  return 0;
}

int binarysearch(int number)
{
  int mid, start = 0, end = LEN - 1;

  assert(is_sorted());

  while(start <= end) {
    assert(mustbe(start, end, number));

    mid = (start + end) / 2;
    if(a[mid] < number)
      start = mid + 1;
    else if(a[mid] > number)
      end = mid - 1;
    else {
      assert(mid >= start && mid <= end && a[mid] == number);
      return mid;
    }
  }
  assert(!contains(number));
  return -1;
}

int main(void)
{
  printf("Search 5 in [%d %d %d %d %d %d %d %d] at %d\n", 
	 a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7],
	 binarysearch(5));
  return 0;
}
