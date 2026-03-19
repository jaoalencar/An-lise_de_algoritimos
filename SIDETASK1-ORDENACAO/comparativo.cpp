#include <iostream>
#include <chrono>
#include <vector>
//#include <algorithm>

using namespace std;

//Struct para mostrar vetor e ordena-lo
struct vetor : vector <int>{
    //vetor é um vector com metodos incrementados
    using vector <int>::vector;
    
    //Métodos de ordenação
    void mergesort(){
        mergesort_logic(*this);
    }
    void quicksort(){

        quicksort_logic(*this, 0, this->size()-1);
    }
    void heapsort(){
        heapsort_logic(*this);
    }
    
    //Função para mostrar o array
    void show(){
        for (int &i: *this)
        {
            cout << i << ", ";
        }
        cout << endl;
    }

    //OPERAÇÕES INTERNAS, ONDE REALMENTE OCORRE A LÓGICA DE ORDENAÇÃO
private:
    void mergesort_logic(vector <int> &array){
        //STOP CONDITION
        if(array.size() < 2) return;

        //Divisão
        int metade = array.size()/2;
        vector <int> rightarray (array.begin(), array.begin()+metade);
        vector <int> leftarray (array.begin()+metade, array.end());
        
        mergesort_logic(leftarray);
        mergesort_logic(rightarray);
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
    void quicksort_logic(vector <int> &array, int inicio, int fim){
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
                std::swap(array[l], array[r]);
                r--;
                l++;
            }
        }
        quicksort_logic(array, inicio, r);
        quicksort_logic(array, l, fim);
    }
    void heapsort_logic(vector <int> &array){
        //Faz a arvore ordenada
        for(int i = (array.size()/2 -1); i>=0; i--){
            heapfy(array, array.size(), i);
        }
        //Coloca o maior valor no final
        for (int i = array.size()-1; i>0; i--)
        {
            //Coloca o valor no final
            std::swap(array[0], array[i]);
            //ordena o heap denovo
            heapfy(array, i, 0);
        }
        
    }
    //HEAPFY -> UTILIZADO NO HEAP SORT
    //  Criação da arvore binária
    //  array -> que será ordenado
    //  n -> limite da ordenação do array
    //  r ->  raiz
    void heapfy(vector <int> &array, int n, int raiz){
        //As raizes vão somente até a metade do vetor, dai pra frente são somente filhos
        int root = raiz;
        //vai descendo até ver que está tudo ordenado
        while (true)
        {
            int l = root*2 + 1;//filho da esquerda
            int r = root*2 + 2;//filho da direta
            int largest = root;//raiz
            
            if(l < n //filho dentro do array a ser ordenado
            && array[l] > array[largest]) largest = l;
            if(r < n //filho dentro do array a ser ordenado
            && array[r] > array[largest]) largest = r;
            
            //se o ptr do maior valor e diferente do root, é pq não está ordenado
            if (largest != root){
                std::swap(array[largest], array[root]);
                root = largest;
            }
            //caso não tenha troca é pq está tudo lindo
            else{
                break;
            }
        }
    }
};

//FUNÇÃO PRINCIAL
int main(){
    vetor lista = {3, 1, 5, 3};
    cout << "Antes da ordenacao: " <<  endl;
    lista.show();
    lista.heapsort();
    cout << "Pos ordenacao: " << endl;
    lista.show();

    return 0;
}