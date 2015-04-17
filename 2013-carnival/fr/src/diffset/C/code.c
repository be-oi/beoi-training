#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int N, M, i, j;
  scanf ("%d %d", &N, &M);

  // Allocation de la memoire
  // Geheugen toewijzen
  int *B = malloc(M * sizeof(int));
  int *A = malloc(N * sizeof(int));

  for (j = 0; j < M; j++) {
    scanf("%d", B+j);
  }

  for (i = 0; i < N; i++) {
    scanf("%d", A+i);
  }

  // A bevat N elementen, geindexeerd van 0 tot N-1
  // B bevat M elementen, geindexeerd van 0 tot M-1
  // A contient N elements. indices de 0 jusque N-1
  // B contient M elements. indices de 0 jusque M-1

  // Votre code devrait venir ici.
  // Zet jouw code hier.



  // Liberation de la memoire
  // Geheugen vrijmaken
  free(A);
  free(B);

  return 0;
}
