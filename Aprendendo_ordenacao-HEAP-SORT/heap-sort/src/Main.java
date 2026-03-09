import java.util.Arrays;


public class Main {
    //Função de ordenaççao
    public static void heapSort(int[] A) {
        //Verifica se o vetor precisa ser ordenado
        //Não se ordena um vetor inexistente = null
        //Não se ordena um vetor de apenas um indice
        if (A == null || A.length < 2) return;

        //pega o tamanho do vetor
        int n = A.length; // n = tamanho do vetor

        //Cria uma arvore ordenada
        //Uma arvore tem raiz e filhos, a raiz é sempre maior que os filhos
        //As raizes somente ocupam metade do tamanho dos vetores
        for (int i = (n / 2) - 1; i >= 0; i--) {
            //começa pela metade do vetor e vai diminuindo
            heapify(A, n, i);
        }


        for (int end = n - 1; end > 0; end--) {
            swap(A, 0, end);
            heapify(A, end, 0);
        }
    }

    //Função que cria uma arvore ordenada no lugar do vetor
    /*
    [] A -> Vetor que tornará arvore
    heapSize -> Tamanho do heap, é o tamanho do vetor
    i -> raiz a ser analizada
     */
    private static void heapify(int[] A, int heapSize, int i) {
        while (true) {
            /*
            no heapfy a raiz é o maior valor.
            o filho da direita é o segundo maior valor
            o filho da esquerda é o menor valor
             */

            //Define variaveis
            int left = 2 * i + 1; //é o filho da esquerda
            int right = 2 * i + 2; //é o filho da direita
            int largest = i; //é a raiz

            //-------
            //Verifica se os filhos são maiores que a raiz e define o indice da raiz
            //-------
            if (left < heapSize //verifia se não está escapando do tamanho do vetor
                && A[left] > A[largest] //Verifica se o filho da esquerda é maior que a raiz
            ){
                largest = left; //define a raiz com o indice do filho
            }
            if (right < heapSize//verifia se não está escapando do tamanho do vetor
            && A[right] > A[largest]//Verifica se o filho da direita é maior que a raiz
            ){
                largest = right;
            }
            //Caso os filhos não sejam maiores que as raizes, retorna e não realiza a troca e retorna
            //Chegou no fim da arvore
            if (largest == i) return;

            //TROCA
            //A raiz vai para a sua posição e o filho para a sua posição correta no vetor
            //Aqui está a ordenação da arvore ou heap
            swap(A, i, largest);

            i = largest;//desce a arvore e ordena os filhos dos filhos
        }
    }

    //Função de troca
    private static void swap(int[] A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }


    public static void main(String[] args) {
        //Vetor que será ordenado
        int[] A = {5, 1, 4, 2, 8, 0, -3, 7, 7};
        //chama a ordenação
        heapSort(A);
        //mostra o vetor ordenado
        System.out.println(Arrays.toString(A));
    }
}
