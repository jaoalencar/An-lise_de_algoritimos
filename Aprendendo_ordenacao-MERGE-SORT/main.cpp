#include <iostream>
#include <vector>
#include <random>
using namespace std;
//Quantidade de itens no vetor
#define MAX 10

void mergesort(vector <int> &array){
    //1° Etapa -> DIVIDIR (inicio da recurção)
    //CODIÇÂO DE PARADA
    //Quando o vetor tive apenas uma posição
    if(array.size() < 2){
        return;
    }
    //divide em dois vetores, o da esquerda e o da direita
    int metade = array.size()/2; //posição que é exatamente a metade do vetor
    vector <int> leftarray(metade); //parte esquerda
    vector <int> rightarray(array.size() - metade); //parte direita
    
    //povoa os dois array
    //ponteiro que vai percorrer os vetores
    int indice = 0; //Esse indice também revela o tamanho do vetor de saida
    
    for (int &i: leftarray) //Povoando array da esquerda
    {
        i = array[indice];
        indice++;
    }
    for (int &i: rightarray) //Povoando array da direita
    {
        i = array[indice];
        indice++;
    }
    //Continua a divisão recursivamente
    mergesort(leftarray);
    mergesort(rightarray);

    //2° Etapa -> Conquistar (merge)
    //Verifica os vetores e qual é maior
    int ptr_right = 0; //ponteiro do vetor da direita
    int ptr_left = 0; //ponteiro do vetor da esquerda

    //Percorre todo o vetor de saida (indice está exatamente com o tamanho do vetor de saida)
    for(int ptr_out = 0; ptr_out < array.size(); ptr_out++){
        //Se os dois vetores ainda estiverem cheios
        if(ptr_left < leftarray.size() && ptr_right < rightarray.size()) 
        {   
            if (leftarray[ptr_left] < rightarray[ptr_right])
            {
                array[ptr_out] = leftarray[ptr_left];
                ptr_left++;
            }
            else{
                array[ptr_out] = rightarray[ptr_right];
                ptr_right++;
            }
        }
        //se somente o direito estiver "cheio"
        else if(ptr_right < rightarray.size()){
            array[ptr_out] = rightarray[ptr_right];
            ptr_right++;
        }
        //se somente o esquerdo estiver cheio
        else
        {
            array[ptr_out] = leftarray[ptr_left];
            ptr_left++;
        }
    }
}

int main(){
        //Criação do vetor
        vector <int> lista(MAX);
        //População do vetor com valores aleatório
        // * "semente" aleatória
        random_device rd;
        mt19937 gerador(rd());
        uniform_int_distribution <int> distribuicao (1, MAX);
        // * atribuição dos valores aleatórios ao vetor
        for (int &i : lista)
        {
            i = distribuicao(gerador);
        }
        //----------------       
        //Mostra o vetor
        cout << "Vetor desordenado: " << endl;
        int indice = 1;
        for (int &i: lista)
        {   
            cout << i << ", ";
            indice++;
        }
        cout << endl << "----------" << endl;
        
        //Ordena o vetor
        mergesort(lista);

        //Mostra o vetor
        cout << "Vetor desordenado: " << endl;
        for (int &i: lista)
        {   
            cout << i << ", ";
            indice++;
        }
    return 0;
}