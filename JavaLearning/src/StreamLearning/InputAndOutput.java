package StreamLearning;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class InputAndOutput {
    private static PrintWriter stdout = new PrintWriter(System.out, true);
    private static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) {
        try {
            String a = stdin.readLine();
            stdout.println(a);
        } catch (Exception e) {
            stdout.println(e);
        }
    }

}
