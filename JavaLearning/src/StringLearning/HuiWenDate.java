package StringLearning;

import java.util.Scanner;

public class HuiWenDate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入日期YYYY MM DD");
        String date = sc.nextLine();
        String[] splitedDate = date.split(" ");
        int year = Integer.parseInt(splitedDate[0]);
        int month = Integer.parseInt(splitedDate[1]);
        int day = Integer.parseInt(splitedDate[2]);
        while (true) {
            if (isHuiWen(year, month, day)) {
                break;
            }
            if (day < 30) {
                day++;
            } else if (month < 12) {
                month++;
                day = 1;
            } else {
                year++;
                month = 1;
                day = 1;
            }
        }
        System.out.println(year + " " + month + " " + day);
    }

    public static boolean isHuiWen(int year, int month, int day) {
        StringBuilder sb = new StringBuilder();
        sb.append(year).append(month).append(day);
        return sb.toString().equals(sb.reverse().toString());
    }
}
