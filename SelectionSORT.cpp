#include <stdio.h>
 
void selectionSort(int a[], int n)
{
    int i, j, min;
 
    
    for (i = 0; i < n-1; i++) //percorre o array.
    {
        
        min = i;
        for (j = i+1; j < n; j++)
		{
	
          if (a[j] < a[min]) // compara o primeiro elemento do array com os demais para encontrar um valor menor.
            min = j;
        }
        int aux = a[i]; // substitui os valores do array dessa vez na ordem correta.
        a[i] = a[min];
        a[min] = aux;
        
    }
}
 

void exibirArray(int a[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
 

int main()
{
    int a[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(a)/4; //divide por 4 pois é o valor em bytes de cada elemento do array.
    
    printf("array original:  ");
    exibirArray(a, n);
    
    selectionSort(a, n);
    
    printf("array ordenado:  ");
    exibirArray(a, n);
    
    return 0;
}
