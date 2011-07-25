#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  char gesture[3][10] = {"scissor", "stone", "cloth"};
  int man, computer, result, ret;

  srand(time(NULL));

  while(1) {
    computer = rand() % 3;
    printf("\nPlease Input: (0-Scissor 1-Stone 2-Cloth):\n");
    ret = scanf("%d", &man);
    if(ret != 1 || man < 0 || man > 2) {
      printf("Please Input: 0, 1 or 2.\n");
      continue;
    }

    printf("Your gesture:: %s\t Computer's gesture: %s\n", 
	   gesture[man], gesture[computer]);

    result = (man - computer + 4) % 3 - 1;

    if(result > 0)
      printf("You Win!\n");
    else if(result == 0) 
      printf("Draw!\n");
    else
      printf("You Lose!\n");
  }
  return 0;
}
