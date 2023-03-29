package StringLearning;

public class Cards {
    public static void main(String[] args) {
        int[] cards = new int[10];
        for (int i = 0; i < 10; i++) {
            cards[i] = 2021;
        }
        int count = 0;
        boolean isAnswer = false;
        while (!isAnswer) {
            count++;
            String num = count + "";
            for (int i = 0; i < num.length(); i++) {
                int numberAtI = num.charAt(i) - '0';
                if (cards[numberAtI] > 0) {
                    cards[numberAtI]--;
                } else {
                    System.out.println(count - 1);
                    isAnswer = true;
                }
            }
        }
    }
}
