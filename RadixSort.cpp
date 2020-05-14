// Implementación de Radix Sort 
#include<iostream> 
using namespace std; 
  
// Función para obtener el máximo valor del arreglo
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// Función para realizar countsort en el arreglo de acuerdo al dígito representado por exp
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // arreglo output
    int i, count[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Se actualiza count[i] para que count[i] ahora contenga la actual
    //  posición de este dígito en output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Se construye el arreglo output
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copia la matriz de salida a arr[], para que arr[] ahora 
    // contenga números ordenados según el dígito actual 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  

void radixsort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
  
    // Se realiza counting sort para cada dígito. Nótese que en vez
    // de pasar el dígito, exp se pasa. exp es 10^i 
    // donde i es el valor actual 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
  
void ImprimirArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
int main() 
{ 
    int arr[] = {134, 45, 73, 90, 604, 25, 2, 66}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    radixsort(arr, n); 
    cout<<"Arreglo Ordenado: "<<endl;
    ImprimirArray(arr, n); 
    return 0; 
} 