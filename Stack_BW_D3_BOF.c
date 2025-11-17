#include <stdio.h>

int main () {

int vector [10], i, j, k;
int swap_var;


printf ("Inserire 10 interi:\n");

// MODIFICA QUI: Cambiato 10 con 500 per causare il Buffer Overflow
for ( i = 0 ; i < 500 ; i++)
	{
	int c= i+1;
	printf("[%d]:", c);
	scanf ("%d", &vector[i]); // Questo scriverà fuori dai limiti dopo i=9
	}


printf ("Il vettore inserito e':\n");
for ( i = 0 ; i < 10 ; i++) // Lasciamo questa stampa a 10
        {
        int t= i+1;
        printf("[%d]: %d", t, vector[i]);
	printf("\n");
	}


for (j = 0 ; j < 10 - 1; j++)
	{
	for (k = 0 ; k < 10 - j - 1; k++)
		{
            // L'overflow potrebbe aver corrotto i dati,
            // quindi l'ordinamento potrebbe fallire o dare risultati strani
			if (vector[k] > vector[k+1]) 
			{
			swap_var=vector[k];
			vector[k]=vector[k+1];
			vector[k+1]=swap_var;
			}
		}
	}
printf("Il vettore ordinato e':\n");
for (j = 0; j < 10; j++)
	{
	int g = j+1;
	printf("[%d]:", g);
	printf("%d\n", vector[j]);
	}

return 0; // Il programma probabilmente crasherà qui (o prima)

}