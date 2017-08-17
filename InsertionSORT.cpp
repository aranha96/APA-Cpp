#include <stdio.h>
 
void insertionSort(int a[], int n)
{
   int i, valor, j;
   for (i = 1; i < n; i++) //percorre o array a partir do segundo elemento.
   {
       valor = a[i];
       j = i-1;
 
       while (j >= 0 && a[j] > valor) //compara os valores e desloca caso o primeiro seja maior.
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = valor; //coloca o menor valor na frente.
   }
}

void ExibirArray(int a[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", a[i]);
   printf("\n");
}
 
 
int main()
{
   int a[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(a)/4; //divide por 4 pois é o tamanho em bytes de cada elemento do array. 
   
    printf("array original:  ");
	ExibirArray(a, n); 
    
    insertionSort(a, n);
    
    printf("array ordenado:  ");
	ExibirArray(a, n); 
 
    return 0;
}
