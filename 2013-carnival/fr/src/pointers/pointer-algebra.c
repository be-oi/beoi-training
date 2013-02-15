#include <stdio.h>

int main() {
  int *ptr;
  int arrayInts[10] = {1,2,3,4,5,6,7,8,9,10};

  ptr = arrayInts; /* ptr = &arrayInts[0]; is also fine */

  printf("The pointer is pointing to the first ");
  printf("array element, which is %d.\n", *ptr);
  printf("Let's increment it.....\n");

  ptr++;

  printf("Now it should point to the next element,");
  printf(" which is %d.\n", *ptr);
  printf("But suppose we point to the 3rd and 4th: %d %d.\n", *(ptr+1),*(ptr+2));

  ptr+=2;

  printf("Now skip the next 4 to point to the 8th: %d.\n", *(ptr+=4));

  ptr--;

  printf("Did I miss out my lucky number %d?!\n", *(ptr++));
  printf("Back to the 8th it is then..... %d.\n", *ptr);

  return 0;
}
