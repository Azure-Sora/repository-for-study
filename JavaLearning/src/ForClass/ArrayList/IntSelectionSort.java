package ForClass.ArrayList;

public class IntSelectionSort {
    public static void main(String[] args) {
        int[] testArray = {3, 6, 2, 1, 5, 4, 8, 7};
        for (int i : testArray) {
            System.out.print(i + " ");
        }
        System.out.println();
        selectionSort(testArray);
        for (int i : testArray) {
            System.out.print(i + " ");
        }
    }

    public static void selectionSort(int[] src) {
        for (int i = 0; i < src.length; i++) {
            int min = src[i];
            int minIndex = i;
            for (int j = i; j < src.length; j++) {
                if (src[j] < min) {
                    min = src[j];
                    minIndex = j;
                }
            }
            int temp = src[i];
            src[i] = src[minIndex];
            src[minIndex] = temp;
        }
    }
}
