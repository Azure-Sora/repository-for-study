package StringLearning.HidePhoneNumber;

import java.util.Scanner;

public class HidePhoneNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String phoneNumber = sc.next();
        String hiddenPhoneNumber = "";
        hiddenPhoneNumber = phoneNumber.substring(0, 3);
        hiddenPhoneNumber = hiddenPhoneNumber + "****";
        hiddenPhoneNumber = hiddenPhoneNumber + phoneNumber.substring(7, 11);
        System.out.println(hiddenPhoneNumber);
    }
}
