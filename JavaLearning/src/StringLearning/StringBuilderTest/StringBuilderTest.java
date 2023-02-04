package StringLearning.StringBuilderTest;

import java.util.Scanner;
import java.util.StringJoiner;

public class StringBuilderTest {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        StringJoiner sj = new StringJoiner(", ", "[", "]");
        for (int i = 0; i < arr.length; i++) {
            sj.add(arr[i] + "");
        }
        System.out.println(sj.toString());
    }
}
