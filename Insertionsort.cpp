// Implementación de InsertionSort
#include <iostream>
using namespace std; 
  

void insertionSort(int arr[], int n)  
{  
    int i, e, j;  
    for (i = 1; i < n; i++) 
    {  
        e = arr[i];  //elemento
        j = i - 1;  
  
        /* Mover elementos del arr[0..i-1], que son  
        mayor que e, a una posición más adelante  
        de su posición actual */
        while (j >= 0 && arr[j] > e) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = e;  
    }  
}  

void ImprimirArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  

int main()  
{  
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    cout<<"Arreglo ordenado: "<<endl;
    insertionSort(arr, n);  
    ImprimirArray(arr, n);  
  
    return 0;  
}  