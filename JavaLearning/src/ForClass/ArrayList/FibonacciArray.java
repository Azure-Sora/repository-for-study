package ForClass.ArrayList;

import java.util.ArrayList;
import java.util.Scanner;

public class FibonacciArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> fibonacci = new ArrayList<>();
        int n = sc.nextInt();
        fibonacci.add(1);
        fibonacci.add(1);
        while (fibonacci.size() < n) {
            fibonacci.add(fibonacci.get(fibonacci.size() - 1) + fibonacci.get(fibonacci.size() - 2));
        }
        for (int i : fibonacci) {
            System.out.println(i);
        }
    }
}
