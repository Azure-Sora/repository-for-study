package ForClass;

import java.util.Arrays;

public class SortTest {
    public static void main(String[] args) {
        int[] arr = {1, 5, 8, 10, 6, 3, 4, 9, 5, 10};
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        System.out.println(Arrays.toString(arr));
    }
}
