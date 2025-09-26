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

//EJERCICIO 3 Busqueda lineal con centinela

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

//EJERCICIO 4 Busqueda Lineal recursiva

int B_lineal_Recursiva(int A[], int tamaño, int x, int i){ 

    int ix=-1;
    if (i >= tamaño) {
        return ix;
    }

    if (A[i] == x){
        return i;
    }
    B_lineal_Recursiva(A, tamaño, x, i+1);

}


//main de prueba
int main(){
    int A[] = {4,1,3,7,5};
    int encont = 3;
    int tamaño = sizeof(A) / sizeof(A[0]);
    //int r = B_lineal(A,encont,tamaño);
    //int r = B_linealM(A,encont,tamaño); 
    //int r = B_lineal_Centinela(A,encont,tamaño); 
    //int r = B_lineal_Recursiva(A,encont,tamaño); 
    if (r>-1){
        printf("elemento %d encontrado en la posición: [%d]", encont, r);
        }
    else{
        printf("elemento %d no ha sido encontrado");
    }

    return 0;
}



        }
    else{
        printf("elemento %d no ha sido encontrado");
    }
}
