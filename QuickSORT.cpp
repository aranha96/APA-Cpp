#include<stdio.h>
 

void trocaArray(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
 
int partArray (int a[], int low, int high)
{
    int pivot = a[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (a[j] <= pivot)
        {
            i++;    
            trocaArray(&a[i], &a[j]);
        }
    }
    trocaArray(&a[i + 1], &a[high]);
    return (i + 1);
}
 

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        
        int p = partArray(a, low, high);
 
       
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
 

void exibirArray(int a[], int tamanho)
{
    int i;
    for (i=0; i < tamanho; i++)
        printf("%d ", a[i]);
    printf("\n\n");
}
 

int main()
{
    int a[] = {10, 70, 81, 19, 11, 5, 26, 0, 1, 9};
    int n = sizeof(a)/4;
    
    printf("Array original: ");
    exibirArray(a, n);
    
    quickSort(a, 0, n-1);
    
	printf("Array ordenado: ");
    exibirArray(a, n);
    
    return 0;
}
