package ForClass;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class IOTest {
    private static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter stdout = new PrintWriter(System.out, true);

    public static void main(String[] args) {
        String a = null;
        try {
            a = stdin.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        stdout.println(a);
        String c = "aa";
        String d = new String("aa");
    }
}
