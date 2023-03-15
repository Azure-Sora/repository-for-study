package start;

import java.util.Scanner;
import java.util.StringJoiner;

public class LearningCodes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
//            System.out.println(divide(sc.nextInt(), sc.nextInt()));
            System.out.println(sc.nextInt() / sc.nextInt());
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }

    public static int divide(int a, int b) {
        if (b == 0) {
            throw new ArithmeticException();
        }
        return a / b;
    }
}