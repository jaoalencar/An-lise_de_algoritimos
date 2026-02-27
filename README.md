# 📊 Análise de Algoritmos: Insertion Sort

Este repositório contém um estudo prático sobre a eficiência do algoritmo **Insertion Sort** (Ordenação por Inserção) utilizando C++. O foco é observar como a organização prévia dos dados impacta o tempo de processamento.

---

## 🎯 Objetivo

Analisar o desempenho do algoritmo em 4 cenários distintos com vetores de **100.000 elementos**.

---

## 🛠️ Metodologia

A medição foi realizada em **microssegundos ($\mu s$)** utilizando a biblioteca `<chrono>`.

### Cenários de Teste:
1.  **Melhor Caso (Ordenado):** Vetor já organizado de forma crescente.
2.  **Meio Ordenado (50%):** O vetor está ordenado do índice 0 até 50.000; o restante está aleatório.
3.  **Caso Aleatório:** Elementos distribuídos sem ordem definida.
4.  **Pior Caso (Invertido):** Vetor organizado de forma decrescente (exige o máximo de trocas).

---

## 📈 Resultados Obtidos

Os dados abaixo refletem a execução do algoritmo para $N = 100.000$:

| Cenário de Teste | Tempo de Execução ($\mu s$) | Tempo em Segundos (aprox.) |
| :--- | :--- | :--- |
| **1. Melhor Caso** | `1.047,00` | ~0.001 s |
| **2. Meio Ordenado (50%)** | `19.968.137,70` | ~19,96 s |
| **3. Caso Aleatório** | `21.267.639,30` | ~21,26 s |
| **4. Pior Caso (Invertido)** | `41.118.148,90` | ~41,11 s |



---

## 🧠 Conclusões

Com base nos testes, as seguintes características do **Insertion Sort** foram observadas:

* **Eficiência Adaptativa:** No **Melhor Caso**, o algoritmo apresenta complexidade $O(n)$, sendo extremamente rápido.
* **Decaimento de Performance:** Quando o vetor não está ordenado, a complexidade sobe para $O(n^2)$. Isso explica por que o tempo salta de milissegundos para quase **41 segundos** no pior caso.
* **Sensibilidade ao Desordenamento:** Mesmo com 50% do vetor ordenado, o tempo de execução foi próximo ao caso totalmente aleatório, evidenciando o alto custo de inserção de novos elementos em grandes estruturas.

---

## 🚀 Como Executar

1. Tenha um compilador C++ instalado (GCC, Clang ou MSVC).
2. Execute o main.cpp
