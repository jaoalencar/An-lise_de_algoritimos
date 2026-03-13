#include <iostream>
#include <vector>
#include <random>

using namespace std;

#define MAX_SIZE 10

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
    for (size_t i : lista)
    {
        cout << i << endl;
    }
    
    
}
