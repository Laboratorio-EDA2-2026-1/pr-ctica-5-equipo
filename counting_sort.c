//Ejercicio 1
#include <stdio.h>
#include <string.h>


void countingSort(char *s) {
    int n = strlen(s);
    int B[26] = {0}; 
    char C[n];

    
    for (int i = 0; i < n; i++) {
        B[s[i] - 'a']++;
    }

    
    for (int i = 1; i < 26; i++) {
        B[i] += B[i - 1];
    }

   
    for (int i = n - 1; i >= 0; i--) {
        C[B[s[i] - 'a'] - 1] = s[i];
        B[s[i] - 'a']--;
    }

   
    for (int i = 0; i < n; i++) {
        s[i] = C[i];
    }
}

int main()
{
    char s[100];
    printf("Danos una cadena de entrada de no mas de 100 caracteres: %s \n", s);
    fgets(s, sizeof(s), stdin);
    printf("Entrada: %s \n", s);
    countingSort(s);
    printf("Salida: %s \n", s);
    return 0;
}

//Ejercicio 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void countingSort(char *s) {
    int n = strlen(s) - 1;
    int C[3] = {0};
    
    for (int i = 0; i < n; i++) {
        switch(s[i]) {
            case 'R':
                C[0]++;
                break;
            case 'B':
                C[1]++;
                break;
            case 'A':
                C[2]++;
                break;
            default:
                printf("Color no reconocido: %c\n", s[i]);
                exit(-1);
                return;
                
        }
    }

    int p = 0;
    for (int i = 0; i < 3; i++) {
        char color;
        switch(i) {
            case 0:
                color = 'R';
                break;
            case 1:
                color = 'B';
                break;
            case 2:
                color = 'A';
                break;
        }
        for (int j = 0; j < C[i]; j++) {
            s[p++] = color;
        }
    }
    s[p] = '\0'; 
}

int main() {
    char s[100];
    printf("Mete una cadena de entrada usando: (R para rojo, B para blanco, A para azul): \n");
    fgets(s, sizeof(s), stdin);
    printf("Entrada: %s", s);
    countingSort(s);
    printf("Salida: %s", s);
    return 0;
}

