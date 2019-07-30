#include <iostream>
using namespace std;
 


void heap(int a[], int n, int i)
{
    int maior = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    
    if (l < n && a[l] > a[maior])
        maior = l;
 
    
    if (r < n && a[r] > a[maior])
        maior = r;
 
    
    if (maior != i)
    {
        swap(a[i], a[maior]);
 
        
        heap(a, n, maior);
    }
}
 

void heapSort(int a[], int tamanho)
{
    
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heap(a, tamanho, i);
 
   
    for (int i = tamanho-1; i >= 0; i--)
    {
        
        swap(a[0], a[i]);
 
        
        heap(a, i, 0);
    }
}
 

void exibirArray(int a[], int tamanho)
{
    for (int i=0; i < tamanho; ++i)
        cout << a[i] << " ";
    cout << "\n\n";
}
 

int main()
{
    int a[] = {112, 211, 131, 56, 61, 37};
    int n = sizeof(a)/4;
    
    cout << "Array original: ";
    exibirArray(a, n);
 
    heapSort(a, n);
 
    cout << "Array ordenado: ";
    exibirArray(a, n);
}
