package StringLearning.ReverseAndCompareStrings;

import java.util.Scanner;

public class ReverseAndCompareStrings {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入字符串A：");
        String a = sc.next();
        System.out.print("请输入字符串B：");
        String b = sc.next();
        boolean whetherSame = false;
        for (int i = 0; i < a.length(); i++) {
            if (a.equals(b)) {
                whetherSame = true;
                break;
            }
            a = reverse(a);
        }
        System.out.println(whetherSame);
    }

    public static String reverse(String source) {
        StringBuilder sb = new StringBuilder();
        sb.append(source.substring(1)).append(source.charAt(0));
        return sb.toString();
    }
}
