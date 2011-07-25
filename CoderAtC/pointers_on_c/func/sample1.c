#include <stdio.h>
#include <stdarg.h>

void binary_to_ascii(unsigned int value) {
  unsigned int quotient;
  quotient = value / 10;
  if (quotient != 0) 
    binary_to_ascii(quotient);
  putchar(value % 10 + '0');
}

void fibonacci(int n) {
  long result;
  long previous_result;
  long next_older_result;

  result = previous_result = 1;
  while( n > 2) {
    n--;
    next_older_result = previous_result;
    previous_result = result;
    result = previous_result + next_older_result;
  }
  printf("fabonacci result = %ld", result);
}

void average(int n_values, ...) {
  va_list var_arg;
  int count;
  float sum = 0;

  va_start(var_arg, n_values);

  for (count = 0; count < n_values; count++) {
    sum += va_arg(var_arg, int);
  }

  va_end(var_arg);

  printf("average = %fd", sum / n_values);
} 

int main(void) {
  //  binary_to_ascii(4267);
  //  fibonacci(10);
  average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  return 0;
}
