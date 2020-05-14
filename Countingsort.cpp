// Implementación de CountingSort 
#include<iostream>
#include<string.h> 
using namespace std;  
#define RANGE 255  
  
void countingSort(char arr[])  
{  
    // El arreglo output que tendrá a los caracteres ordenados
    char output[strlen(arr)];  
  
    //Crear una matriz llamada count para almacenar a cada individuo, inicializar la matriz en 0  
    int count[RANGE + 1], i;  
    memset(count, 0, sizeof(count));  
  
    // Almacena el count de cada caracter
    for(i = 0; arr[i]; ++i)  
        ++count[arr[i]];  
  

    for (i = 1; i <= RANGE; ++i)  
        count[i] += count[i-1];  
  
    //Construimos el arreglo output
    for (i = 0; arr[i]; ++i)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  
  
    // Se copia el arreglo output a arr, para que así arr contenga los caracteres ordenados
    for (i = 0; arr[i]; ++i)  
        arr[i] = output[i];  
}  
  
int main()  
{  
    char arr[] = "fldsmdfr"; 
    countingSort(arr);  
    cout<< "Arreglo ordenado: " << arr;  
    return 0;  
}  
 