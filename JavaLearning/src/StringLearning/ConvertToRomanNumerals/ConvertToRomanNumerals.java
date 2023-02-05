package StringLearning.ConvertToRomanNumerals;

import java.util.Scanner;

public class ConvertToRomanNumerals {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = null;
        while (true) {
            boolean whetherInputInvalid = false;
            input = sc.next();
            for (int i = 0; i < input.length(); i++) {
                if (!(input.charAt(i) >= '0' && input.charAt(i) <= '9') || input.length() >= 10) {
                    whetherInputInvalid = true;
                    break;
                }
            }
            if (whetherInputInvalid) {
                System.out.println("输入无效！");
            } else {
                break;
            }
        }
        String romanNumerals = convert(input);
        System.out.println(romanNumerals);
    }

    public static String convert(String input) {
        StringBuilder sb = new StringBuilder();
        String[] romanNumerals = {" ", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        for (int i = 0; i < input.length(); i++) {
            int index = input.charAt(i) - '0';
            sb.append(romanNumerals[index]).append(" ");
        }

        return sb.toString();
    }


}
