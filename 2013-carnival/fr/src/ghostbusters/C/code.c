#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int L, K, l, k;

  scanf ("%d %d", &L, &K);

  // Geheugen toewijzen
  // Allocation de la memoire
  int **I = malloc(L * sizeof(int*));
  for (l = 0; l < L; l++) {
    I[l] = malloc(K * sizeof(int));
    for (k = 0; k < K; k++)
      scanf("%d", &(I[l][k]));
  }

  // I bevat L arrays, geindexeerd van 0 tot L-1
  // Iedere array stelt een rij van K jagers voor, geindexeerd van 0 tot K-1
  // I contient L tableaux. Indices de 0 jusque L-1
  // Chaque tableau represente une instance avec K chasseurs. Indices de 0 jusque K-1
  
  // Zet jouw code hier.
  // Votre code devrait venir ici.



  // Geheugen vrijmaken
  // Liberation de la memoire
  for(l = 0; l < L; l++) {
    free(I[l]);
  }
  free(I);

  return 0;
}
