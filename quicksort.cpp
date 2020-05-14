/*Implementacion de QuickSort */
#include <iostream>
using namespace std;  
  

void intercambio(int* a, int* b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  
/* Esta función toma el último elemento como pivote, coloca  
el elemento pivotante en su posición correcta en la clasificación  
y coloca a todos los más pequeños que el pivote 
a la izquierda del pivote y todos los elementos mayores a la derecha  
de pivote */
int particion (int arr[], int low, int high)  
{  
    int pivote = arr[high]; // pivot  
    int i = (low - 1); // índice del elemento más pequeño 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // Si el elemento actual es más pequeño que el pivote 
        if (arr[j] < pivote)  
        {  
            i++; // incremento del index del elemento más pequeño
            intercambio(&arr[i], &arr[j]);  
        }  
    }  
    intercambio(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* Función que implementa el QuickSort   
low(bajo) --> Índice de comienzo,  
high(alto) --> índice de finalización */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* ip es el índice de particionamiento, arr[p] está ahora en el lugar correcto */
        int ip = particion(arr, low, high);  
   
        // Se va a realizar la particion constantemente 
        quickSort(arr, low, ip - 1);  
        quickSort(arr, ip + 1, high);  
    }  
}  
  
void ImprimirArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  

int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Arreglo ordenado: \n";  
    ImprimirArray(arr, n);  
    return 0;  
} 