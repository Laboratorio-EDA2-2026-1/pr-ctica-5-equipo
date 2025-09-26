// Escribe aquí la implementación de los ejercicios de búsqueda lineal.

//EJERCICIO 1 Busqueda Lineal

int B_lineal(int A[], int x, int tamaño){ 
    int ix = -1;
    int encontrado;
    
    for(int i=0; i< tamaño; i++){
         if (A[i] == x) {
            encontrado = i;  
        }
    }
    return encontrado;

}


int main(){
    int A[] = {4,1,3,7,5};
    int encont = 3;
    int tamaño = sizeof(A) / sizeof(A[0]);
    int r = B_lineal(A,encont,tamaño);
    if (r>-1){
        printf("elemento %d encontrado en la posición: [%d]", encont, r);
        }
    else{
        printf("elemento %d no ha sido encontrado");
    }
}

//EJERCICIO 2 Busqueda Lineal "mejorada"

int B_linealM(int A[], int x, int tamaño){ 
    int ix = -1;
    
    for(int i=0; i< tamaño; i++){
         if (A[i] == x) {
            return i;  
        }
    }
    return ix;

}


int main(){
    int A[] = {4,1,3,7,5};
    int encont = 3;
    int tamaño = sizeof(A) / sizeof(A[0]);
    int r = B_linealM(A,encont,tamaño);
    if (r>-1){
        printf("elemento %d encontrado en la posición: [%d]", encont, r);
        }
    else{
        printf("elemento %d no ha sido encontrado");
    }
}

//EJERCICIO 3

int B_lineal_Centinela(int A[], int x, int tamaño){ 
    int ix=-1;
    int temp = A[tamaño-1];
    A[tamaño-1] = x;
    int k=0;
    while (A[k]!=x)
    {
        k++;
    }

    A[tamaño-1] = temp;
    if (k < tamaño - 1 || A[tamaño - 1] == x) {
        return k;
    }

    return ix;
}

int main(){
    int A[] = {4,1,3,7,5};
    int encont = 3;
    int tamaño = sizeof(A) / sizeof(A[0]);
    int r = B_lineal_Centinela(A,encont,tamaño);
    if (r>-1){
        printf("elemento %d encontrado en la posición: [%d]", encont, r);
        }
    else{
        printf("elemento %d no ha sido encontrado");
    }
}
