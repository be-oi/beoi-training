#include <stdio.h>
#include <stdlib.h>

int main() {
  char array[50];
  char *ptr;
  
  printf("Now enter another string less than 50");
  printf(" characters with spaces: \n");
  gets(array);

  printf("\nYou entered: ");
  puts(array);

  printf("\nTry entering a string less than 50");
  printf(" characters, with spaces: \n");
  
  ptr = (char *) malloc(sizeof(array));
  
  scanf("%s", ptr);

  printf("\nYou entered: %s\n", ptr);

  return 0;
}
