#include <iostream>

using namespace std;

void insersion_sort_crescente (int *arr, int tam){
    //Ordena o vetor de forma crescente
    int key, j;
    for (size_t i = 1; i < tam; i++)
    {
        key = arr[i];
        for(j = i; (j>0) && (key<arr[j-1]); j--){
            arr[j] = arr[j-1];
        }
        arr[j] = key;
    }    
}

void show_array (int *vetor, int tam){
    for (size_t i = 0; i < tam; i++)
    {
        cout << vetor[i] << " ";
    }
}
int main() {
    int vetor[] = {3, 6, 5, 1, 4, 2};
    int tam = sizeof(vetor)/sizeof(int);
    cout << "Array desordenado: ";
    show_array(vetor, tam);
    cout << endl;

    cout << "Array ordenado: ";
    insersion_sort_crescente(vetor, tam);
    show_array(vetor, tam);
    cout << endl;
    
    return 0;
}