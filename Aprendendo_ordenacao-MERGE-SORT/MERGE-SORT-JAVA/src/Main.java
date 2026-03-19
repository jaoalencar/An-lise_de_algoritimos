import java.util.Arrays;

public class Main{

    public static void mergeSort(int[] A, int esquerda, int direita) {
        if (esquerda < direita) {
            int meio = (esquerda + direita) / 2;

            mergeSort(A, esquerda, meio);
            mergeSort(A, meio + 1, direita);

            merge(A, esquerda, meio, direita);
        }
    }

    private static void merge(int[] A, int esquerda, int meio, int direita) {
        int n1 = meio - esquerda + 1;
        int n2 = direita - meio;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = A[esquerda + i];
        }

        for (int j = 0; j < n2; j++) {
            R[j] = A[meio + 1 + j];
        }

        int i = 0, j = 0;
        int k = esquerda;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            A[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            A[k] = R[j];
            j++;
            k++;
        }
    }

    public static void main(String[] args) {
        int[] vetor = {12, 11, 13, 5, 6, 7};

        mergeSort(vetor, 0, vetor.length - 1);
        System.out.println(Arrays.toString(vetor));
    }
}