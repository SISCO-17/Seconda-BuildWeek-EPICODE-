#include <stdio.h>

int main () {

    int vector[500], i, j, k;
    int swap_var;
    int scelta;
    int limite_input;

    printf("--- Esercizio Buffer Overflow ---\n");
    printf("Scegli la modalita' di esecuzione:\n");
    printf("1. Programma Corretto (Sicuro - buffer 500)\n");
    printf("2. Programma Vulnerabile (BOF - buffer 10)\n");
    printf("Inserisci la tua scelta (1 o 2): ");
    
    scanf("%d", &scelta);
    
    if (scelta == 1)
    {
        printf("\n--- Modalita' Corretta (limite 500) ---\n");
        printf("Inserire 500 interi:\n");
        limite_input = 500;
        
        for (i = 0; i < limite_input; i++)
        {
            int c = i + 1;
            printf("[%d]: ", c);
            
            while (scanf("%d", &vector[i]) != 1)
            {
                printf("Errore! Inserire un numero intero valido.\n");
                while (getchar() != '\n');
                printf("[%d]: ", c);
            }
        }
        
        printf("\nIl vettore inserito e':\n");
        for (i = 0; i < limite_input; i++)
        {
            int t = i + 1;
            printf("[%d]: %d", t, vector[i]);
            printf("\n");
        }
        
        for (j = 0; j < limite_input - 1; j++)
        {
            for (k = 0; k < limite_input - j - 1; k++)
            {
                if (vector[k] > vector[k+1])
                {
                    swap_var = vector[k];
                    vector[k] = vector[k+1];
                    vector[k+1] = swap_var;
                }
            }
        }
        
        printf("\nIl vettore ordinato e':\n");
        for (j = 0; j < limite_input; j++)
        {
            int g = j + 1;
            printf("[%d]: ", g);
            printf("%d\n", vector[j]);
        }
    }  // <-- Chiusura if (scelta == 1)
    else if (scelta == 2)
    {
        printf("\n--- Modalita' Vulnerabile (BOF) ---\n");
        printf("ATTENZIONE: Questa modalita' causa Buffer Overflow!\n");
        printf("Inserire 500 interi (buffer di soli 10):\n");
        
        int small_vector[10];
        
        for (i = 0; i < 500; i++)
        {
            int c = i + 1;
            printf("[%d]: ", c);
            scanf("%d", &small_vector[i]);
        }
        
        printf("\nTentativo di stampare il vettore...\n");
        for (i = 0; i < 10; i++)
        {
            int t = i + 1;
            printf("[%d]: %d", t, small_vector[i]);
            printf("\n");
        }
        
        printf("\n[!] Se arrivi qui, il BOF non ha causato crash immediato\n");
    }  // <-- Chiusura else if (scelta == 2)
    else
    {
        printf("\nScelta non valida! Il programma termina.\n");
        return 1;
    }
    
    return 0;
}  // Chiusura main()
