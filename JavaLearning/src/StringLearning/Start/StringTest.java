package StringLearning.Start;

import java.util.Scanner;

public class StringTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("请输入字符串：");
        String str = sc.next();
        int upperCount = 0;
        int downCount = 0;
        int numberCount = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= '0' && str.charAt(i) <= '9') {
                numberCount++;
            } else if (str.charAt(i) >= 'a' && str.charAt(i) < 'z') {
                downCount++;
            } else if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
                upperCount++;
            }
        }
        System.out.printf("大写%d个，小写%d个，数字%d个", upperCount, downCount, numberCount);
    }
}
