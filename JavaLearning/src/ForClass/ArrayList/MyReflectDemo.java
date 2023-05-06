package ForClass.ArrayList;
import java.io.*;
import java.lang.reflect.*;
public class MyReflectDemo {
    public static void main(String[] args) {
        try {
            BufferedReader readIn = new BufferedReader(
                    new InputStreamReader(System.in));
            System.out.println("输入一个Java 类的全名：");
            Class<?> c = Class.forName(readIn.readLine());
            Field[] f = c.getDeclaredFields();
            Method[] m = c.getDeclaredMethods();
            Constructor[] con = c.getDeclaredConstructors();
            for (int i = 0; i < m.length; i++)
                System.out.println(m[i].toString());
            for (int i = 0; i < f.length; i++)
                System.out.println(f[i].toString());
            for (int i = 0; i < con.length; i++)
                System.out.println(con[i].toString());
        } catch (Throwable e) {
            System.err.println(e);
        }
    }
}
