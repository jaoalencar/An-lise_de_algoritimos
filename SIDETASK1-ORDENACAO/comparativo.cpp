#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//Struct para mostrar vetor e ordena-lo
struct vetor {
    vector <int> array;
    void mergesort(){
        mergesort(this->array);
    }
    void quicksort(){
        quicksort(this->array, 0, this->array.size()-1);
    }
    //Função para mostrar o array
    void show(){
        for (int &i: array)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
private:
    void mergesort(vector <int> &array){
        //STOP CONDITION
        if(array.size() < 2) return;

        //Divisão
        int metade = array.size()/2;
        vector <int> rightarray (array.begin(), array.begin()+metade);
        vector <int> leftarray (array.begin()+metade, array.end());
        
        mergesort(leftarray);
        mergesort(rightarray);
        //Conquista
        int ptr_left = 0;
        int ptr_right = 0;
        int ptr_out = 0;

        while (ptr_left < leftarray.size() && ptr_right < rightarray.size())
        {
            if (leftarray[ptr_left] < rightarray[ptr_right])
            {
                array[ptr_out++] = leftarray[ptr_left++];
            }
            else{
                array[ptr_out++] = rightarray[ptr_right++];
            }
        }
        while (ptr_left < leftarray.size()) array[ptr_out++] = leftarray[ptr_left++];
        while (ptr_right < rightarray.size()) array[ptr_out++] = rightarray[ptr_right++];
    }
    void quicksort(vector <int> &array, int inicio, int fim){
        //CONDIÇÃO DE PARADA
        if(inicio >= fim){
            return;
        }

        int r = fim;
        int l = inicio;
        int pivot = array[inicio + (fim - inicio)/2]; //pivo é sempre o meio do vetor

        //percorre até achar um menor que o pivot
        while (r >= l)
        {
            while (array[l] < pivot) l++;
            while (array[r] > pivot) r--;

            if(r>=l) {
                swap(array[l], array[r]);
                r--;
                l++;
            }
        }
        quicksort(array, inicio, r);
        quicksort(array, l, fim);
    }
};


//ORDENAÇÕES

//FUNÇÃO PRINCIAL
int main(){
    vetor lista;
    lista.array = {1, 4, 9, 2, 6, 4, 3, 8};
    cout << "Antes da ordenacao: " <<  endl;
    lista.show();
    lista.mergesort();
    cout << "Pos ordenacao: " << endl;
    lista.show();
    return 0;
}