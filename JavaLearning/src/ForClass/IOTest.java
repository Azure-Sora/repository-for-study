package ForClass;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class IOTest {
    private static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter stdout = new PrintWriter(System.out, true);

    public static void main(String[] args) {
        String a = null;
        Scanner sc = new Scanner(System.in);
        try {
            a = stdin.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        StringTokenizer st = new StringTokenizer(a, " ");
        String[] s = new String[0];
        while (st.hasMoreTokens()) {
            s = extendArray(s, 1);
            s[s.length - 1] = st.nextToken();
        }
        for (String ele : s) {
            System.out.println(ele);
        }
        /*System.out.println(add(10,5));*/

    }

    public static String[] extendArray(String[] src, int length) {
        String[] newS = new String[src.length + length];
        System.arraycopy(src, 0, newS, 0, src.length);
        return newS;
    }

    /*public static <T extends Number> T add(T num1, T num2) {

    }*/
}
