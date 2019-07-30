#include<stdlib.h>
#include<stdio.h>
 
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int tam_esq = m - l + 1;
    int tam_dir =  r - m;
 
    
    int esq[tam_esq], dir[tam_dir];//arrays temporários
 
   
    for (i = 0; i < tam_esq; i++)//copia o array original para o array da esquerda [l...m]
        esq[i] = a[l + i];
    for (j = 0; j < tam_dir; j++)//copia o array original para o array da direita [m+1...r]
        dir[j] = a[m + 1+ j];
 
    //valores auxiliares
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < tam_esq && j < tam_dir)//copia os menores valores primeiro no array original
    {
        if (esq[i] <= dir[j])
        {
            a[k] = esq[i];
            i++;
        }
        else
        {
            a[k] = dir[j];
            j++;
        }
        k++;
    }
 
    
    while (i < tam_esq)//copia os demais valores de esq[]
    {
        a[k] = esq[i];
        i++;
        k++;
    }
 
    
    while (j < tam_dir)//copia os demais valores de dir[]
    {
        a[k] = dir[j];
        j++;
        k++;
    }
}
 

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        
        int m = l+(r-l)/2;
 
        
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
 
        merge(a, l, m, r);
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
    int a[] = {12, 11, 15, 25, 16, 7, 4, 2, 0, 17};
    int tamanho = sizeof(a)/4;
 
    printf("Array original: ");
    exibirArray(a, tamanho);
 
    mergeSort(a, 0, tamanho - 1);
 
    printf("Array ordenado: ");
    exibirArray(a, tamanho);
    return 0;
}
