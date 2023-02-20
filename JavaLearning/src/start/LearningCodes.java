package start;

import java.util.Scanner;
import java.util.StringJoiner;

public class LearningCodes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringJoiner sj = new StringJoiner(", ");
        int num = -1;
        while(num != 0){
            sj.add(toLetters(sc.nextInt()));
        }
        String result = sj.toString();
        System.out.println(result);
    }
    public static String toLetters(int num){
        String[] source = {"I","II","III","IV","V"};
        return source[num-1];
    }
}