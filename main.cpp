#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Implementação do Insertion Sort
void insertion_sort(vector<int>& arr) {
    int tam = arr.size();
    for (int i = 1; i < tam; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para medir e imprimir com precisão decimal
void medir_caso(string nome, vector<int> v) {
    auto t0 = chrono::high_resolution_clock::now();
    
    insertion_sort(v);
    
    auto tf = chrono::high_resolution_clock::now();

    // Medindo em microssegundos com precisão double
    chrono::duration<double, micro> duracao = tf - t0;

    cout << left << setw(30) << nome 
         << ": " << fixed << setprecision(4) << duracao.count() << " us" << endl;
}

int main() {
    #ifdef _WIN32
        system("chcp 65001 > nul"); // Corrige acentuação no Windows
    #endif

    const int TAM = 100000;
    vector<int> v_base(TAM);
    for(int i = 0; i < TAM; i++) v_base[i] = i + 1;

    cout << "Análise de Performance - Insertion Sort (Tamanho " << TAM << ")" << endl;
    cout << "--------------------------------------------------------------" << endl;

    // 1. Melhor Caso: 100% Ordenado
    medir_caso("1. Melhor Caso (Ordenado)", v_base);

    // 2. Meio Ordenado: 1 a 50 em ordem, 51 a 100 embaralhados
    vector<int> v_meio = v_base;
    auto rd = mt19937{random_device{}()};
    // Embaralha apenas do índice 50 até o final
    shuffle(v_meio.begin() + 50, v_meio.end(), rd);
    medir_caso("2. Meio Ordenado (50%)", v_meio);

    // 3. Caso Aleatório: Tudo embaralhado
    vector<int> v_aleatorio = v_base;
    shuffle(v_aleatorio.begin(), v_aleatorio.end(), rd);
    medir_caso("3. Caso Aleatorio", v_aleatorio);

    // 4. Pior Caso: 100% Invertido
    vector<int> v_invertido = v_base;
    reverse(v_invertido.begin(), v_invertido.end());
    medir_caso("4. Pior Caso (Invertido)", v_invertido);

    cout << "--------------------------------------------------------------" << endl;
    cout << "Unidade: us (microssegundos)" << endl;

    return 0;
}