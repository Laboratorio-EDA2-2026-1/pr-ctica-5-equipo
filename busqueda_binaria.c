// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
//Ejercicio 1

#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];  // elegimos el último
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]); 
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return i+1; 
}

void quicksort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int piv = particion(arr, bajo, alto);
        quicksort(arr, bajo, piv - 1);
        quicksort(arr, piv + 1, alto);
    }
}

void imprimir_arreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int busqueda_binaria(int arr[], int l, int r, int o){

	if (l > r){
		return -1;
	}

	int m = (l + r) / 2;

	if (arr[m] == o){
		return m;
	}

	if (arr[m] < o){
		return busqueda_binaria(arr, m+1, r, o);
	}else{
		return busqueda_binaria(arr, l, m-1, o);
	}
}

int main(void) {
    int n, o;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Error: memoria insuficiente.\n");
        return 1;
    }

    printf("Ingrese los %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Arreglo ingresado:\n");
    imprimir_arreglo(arr, n);

    quicksort(arr, 0, n - 1); 

    printf("Ingrese el elemento a buscar:\n");
    scanf("%d", &o);

	int result = busqueda_binaria(arr, 0, n-1, o);
	if (result != -1){
		printf("Elemento %d encontrado en la posición %d\n", o, result);
	}else{
		printf("Elemento %d no encontrado\n", o);
		}	
	free(arr);
    return 0;
}		
	
