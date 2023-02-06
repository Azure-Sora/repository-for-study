package StringLearning.Start;

import java.util.Random;
import java.util.Scanner;

public class StringTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rd = new Random();
        StringBuilder sb = new StringBuilder();
        String numStr1 = sc.next();
        String numStr2 = sc.next();
        int num1 = toNumber(numStr1);
        int num2 = toNumber(numStr2);
        int result = num1 * num2;
        String resultArr = result+"";
        System.out.println(resultArr);
        /*int numberIndex = rd.nextInt(5);//生成五位验证码
        for (int i = 0; i < 5; i++) {
            if (i == numberIndex) {
                sb.append(rd.nextInt(10));
            } else {
                if (rd.nextBoolean()) {
                    sb.append((char) rd.nextInt('a', 'z' + 1));
                } else {
                    sb.append((char) rd.nextInt('A', 'Z' + 1));
                }
            }
        }
        String verificationCode = sb.toString();
        System.out.println(verificationCode);*/

        /*String str = sc.next();//打乱输入的字符串
        char[] charArr = str.toCharArray();
        for (int i = 0; i < charArr.length; i++) {
            int randomIndex = rd.nextInt(charArr.length);
            char temp = charArr[i];
            charArr[i] = charArr[randomIndex];
            charArr[randomIndex] = temp;
        }
        String newStr = new String(charArr);
        System.out.println(newStr);*/
    }

    public static int toNumber(String source) {
        int result = 0;
        for (int i = 0; i < source.length(); i++) {
            result *= 10;
            result += source.charAt(i) - '0';
        }
        return result;
    }
}
