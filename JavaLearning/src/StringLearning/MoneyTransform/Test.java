package StringLearning.MoneyTransform;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String money = sc.next();
        char[] transformedMoney = new char[]{'零', '佰', '零', '拾', '零', '万', '零', '千', '零', '佰', '零', '拾', '零', '元'};
        int point = 12;
        for (int i = money.length() - 1; i >= 0; i--) {
            switch (money.charAt(i)) {
                case '0' -> transformedMoney[point] = '零';
                case '1' -> transformedMoney[point] = '壹';
                case '2' -> transformedMoney[point] = '贰';
                case '3' -> transformedMoney[point] = '叁';
                case '4' -> transformedMoney[point] = '肆';
                case '5' -> transformedMoney[point] = '伍';
                case '6' -> transformedMoney[point] = '陆';
                case '7' -> transformedMoney[point] = '柒';
                case '8' -> transformedMoney[point] = '捌';
                case '9' -> transformedMoney[point] = '玖';
            }
            point -= 2;
        }
        System.out.println(money);
        System.out.println(transformedMoney);
    }
}
