#include <iostream>
#include <vector>
#include <random>

using namespace std;

#define MAX_SIZE 10
//Função quick_sort passa apenas a lista
void quick_sort(vector <int> &lista);
void quick_sort(vector <int> &lista, int start_position, int end_position);

void quick_sort(vector <int> &lista){
    //Chama a verdadeira função quick_sort passando o primeiro e ultimo indice
    quick_sort(lista, 0, lista.size() -1);
}
void quick_sort(vector <int> &lista, int start_position, int end_position){
    int pivot = lista[(start_position + end_position)/2]; //pivo, meio do vetor, valor que será analisado como base
    int l = start_position; //indice a esquerda do vetor
    int r = end_position; //indice da direita do vetor

    while (l <= r)
    {
        //Se o valor da esquerda for menor que o pivo está na posição correta
        //Logo passa pro próximo até achar um que não está na posição correta
        while (lista[l]<pivot) l++; //esquerda vai se movendo para o final do vetor, ou seja direita
        
        //Se o valor da direita for maior que o pivo, está na posição correta
        //Logo passa para o proximo até achar um que não está na posição correta
         //Vai movendo para o inicio do veto, logo a esquerda
        while (lista[r]>pivot) r--;

        //se o indice da esquerda, não for maior que o da direita:
        //Troca o valor[r] pelo valor[l]
        if (r >= l)
        {
            //Troca e move o direita e esquerda
            swap(lista[l], lista[r]);
            r--;
            l++;
        }
    }
    //Chama denovo a ordenação quick sort
    //Mas agora passando o valor de inicio e fim novos
    //ou seja o novo fim: l e o novo inicio r, dividindo em dois vetores
        
    //Somente se o inicio for menor que o "fim"(r)
    if (start_position < r)
    {
        quick_sort(lista, start_position, r);
    }
    //somente se o final não for menor que o "inicio"(l)
    if (end_position > l)
    {
        quick_sort(lista, l, end_position);
    }

    
}

int main(){
    //Lista aleatória com MAX valores
    vector <int> lista(MAX_SIZE);

    //Semente aleatoria
    random_device rd;
    mt19937 gerador(rd());
    uniform_int_distribution <int> distribuicao (1, MAX_SIZE); //Aleatorio de 1 até MAX_SIZE

    for (int &i : lista){
        //Atribui o numero aleatório
        i = distribuicao(gerador);
    }

    quick_sort(lista);

    //Mostra a lista
    for (size_t i : lista)
    {
        cout << i << endl;
    }
}
