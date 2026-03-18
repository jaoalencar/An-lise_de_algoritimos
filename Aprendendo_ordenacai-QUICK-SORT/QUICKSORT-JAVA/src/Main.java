import java.util.Arrays;

public class Main{

    public static void quickSort(int[] A, int inicio, int fim) {
        if (inicio < fim) {
            int pivoIndex = particionar(A, inicio, fim);
            quickSort(A, inicio, pivoIndex - 1);
            quickSort(A, pivoIndex + 1, fim);
        }
    }

    private static int particionar(int[] A, int inicio, int fim) {
        int pivo = A[fim];
        int i = inicio - 1;

        for (int j = inicio; j < fim; j++) {
            if (A[j] <= pivo) {
                i++;
                trocar(A, i, j);
            }
        }

        trocar(A, i + 1, fim);
        return i + 1;
    }

    private static void trocar(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    public static void main(String[] args) {
        int[] vetor = {10, 7, 8, 9, 1, 5};

        //System.out.println(vetor[-1]);

        quickSort(vetor, 0, vetor.length - 1);

        System.out.println("Vetor ordenado pelo Quick Sort:");
        System.out.println(Arrays.toString(vetor));
    }
}
