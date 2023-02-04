package start;

import java.util.Random;
import java.util.Scanner;

public class LearningCodes {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Random random = new Random();
        int[] awards = {2, 588, 888, 1000, 10000};
        int temp;
        for (int i = 0; i < awards.length; i++) {
            int index = random.nextInt(5);
                temp = awards[i];
                awards[i] = awards[index];
                awards[index] = temp;

        }
        for (int i = 0; i < awards.length; i++) {
            System.out.println(awards[i] + "元的奖金被抽出");
        }
    }
}