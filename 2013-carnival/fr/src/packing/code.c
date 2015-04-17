#include <unistd.h>
#include <stdio.h>


int estlibre(int h, int l, int i, int j)
{
	
}

int 
main (int argc, char **argv)
{
	int L, H, C, h, l, i;
	scanf ("%d %d %d", &L, &H, &C);
	
	// --------------------------------------------------
	// --------------------------------------------------
	// Je mag de code hierboven niet aanpassen.	
	// Vous n'etes pas cense modifier le code ci-dessus.		
	// --------------------------------------------------
	// --------------------------------------------------

	for (c = 0; c < C; c++)
	{
		scanf ("%d %d", &l, &h); // input
		
		for (i = 0, i < L; i++)
		{
			for (j = 0, j < H; j++) 
			{
				if (estlibre(h, l, i, j) = 0)
				{
					/* on place */
				}
			}
		}
		
		printf("%d %d\n", i, i); // output
	}

	// --------------------------------------------------
	// --------------------------------------------------
	// Je mag de code hieronder niet aanpassen.
	// Vous n'etes pas cense modifier le code ci-dessous		
	// --------------------------------------------------
	// --------------------------------------------------
	
	return 0;
}
