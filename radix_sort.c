#include <stdio.h>
void countsort(int a[],int n,int pos){
	int salida[n+1];
	int maximo = (a[0] / pos)%10;
	for(int i=1;i<n;i++){
		if((a[i]/pos) > maximo){
			maximo = (a[i]/pos)%10;
		}
	}
	int b[maximo+1];
	int c[maximo+1];
	for(int i=0;i<n+1;i++){
		b[i]=0; c[i]=0;
	}
	for(int i=0;i<n;i++){
		c[(a[i]/pos)%10]++;
	}
	for(int i = 1;i<10;i++){
		c[i]+=c[i-1];
	}
	for(int j =n-1;j>=0;j--){
		salida[c[(a[j]/pos)%10]-1]= a[j];
		c[(a[j]/pos)%10]--;
		//b[c[a[j]]-1]=a[j];
		//c[a[j]]=c[a[j]]-1;
	}
	for(int i=0;i<n;i++){
		a[i]=salida[i];
	}
}
void radixSort(int a[],int n){
	int maximo = a[0];
	for(int i=1;i<n;i++){
		if(a[i]> maximo){
			maximo = a[i];
		}
	}
	for(int pos = 1;maximo/pos > 0;pos*=10){
		countsort(a,n,pos);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	printf("Arreglo desordenado:\n");
	for(int i=0;i<n;i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
	radixSort(ar,n);
	printf("Arreglo ordenado:\n");
	for(int i=0;i<n;i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
}
