package ForClass;

import java.util.Scanner;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class InputAndPrintThreeNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        StringTokenizer st = new StringTokenizer(input, ",");
        StringJoiner sj = new StringJoiner(",");
        for (int i = 0; i < 3; i++) {
            sj.add(st.nextToken());
        }
        System.out.println(sj);
    }
}
