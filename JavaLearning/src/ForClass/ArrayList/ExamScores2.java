package ForClass.ArrayList;

public class ExamScores2 {
    public static void main(String[] cmdLines) {
        if (cmdLines == null) {
            System.err.println("请从命令行中输入分数.");
            System.exit(1);
        }
        int[] scores = new int[cmdLines.length];
        for (int i = 0; i < cmdLines.length; i++) {
            scores[i] = Integer.parseInt(cmdLines[i]);
        }
        printAll(scores);
        printMax(scores);
        printMin(scores);

    }
    public static void printAll(int[] scores) {
        for (int i = 0; i < scores.length; i++) {
            System.out.println(scores[i]);
        }
    }
    public static void printMax(int[] scores) {
        int max = scores[0];
        for (int i = 0; i < scores.length; i++) {
            if (scores[i] > max)
                max = scores[i];
        }
        System.out.println("最高分是 " + max);
    }
    public static void printMin(int[] scores) {
        int min = scores[0];
        for (int i = 0; i < scores.length; i++) {
            if (scores[i] < min)
                min = scores[i];
        }
        System.out.println("最低分是 " + min);
    }
}
