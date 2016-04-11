#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int N, M, i, j, a, b;

  scanf ("%d %d", &N, &M);

  int *B = malloc( M * sizeof(int) );
  int *A = malloc( N * sizeof(int) );

  for (j = 0; j < M; j++) {
    scanf("%d", B+j);
  }
  for (i = 0; i < N; i++) {
    scanf("%d", A+i);
  }
  
  // --------------------------------------------------
  // --------------------------------------------------
  // Je mag de code hierboven niet aanpassen.	
  // Vous n'etes pas cense modifier le code ci-dessus.		
  // --------------------------------------------------
  // --------------------------------------------------
  
  j = 0;
  
  for (i = 0; i < N; i++) {
    if (j < M && A[i] == B[j]) {
      j += 1;
    } else {
      printf("%d\n", A[i]);
    }
  }
  
  // --------------------------------------------------
  // --------------------------------------------------
  // Je mag de code hieronder niet aanpassen.
  // Vous n'etes pas cense modifier le code ci-dessous		
  // --------------------------------------------------
  // --------------------------------------------------

  free(B);
  free(A);

  return 0;
}
