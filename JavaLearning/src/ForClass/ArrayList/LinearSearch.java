package ForClass.ArrayList;

import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        char searchFor = sc.next().charAt(0);
        int count = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == searchFor) {
                System.out.println(i);
                count++;
            }
        }
        System.out.println("共有" + count + "个");

    }
}

