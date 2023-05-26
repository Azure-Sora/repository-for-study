package StreamLearning;

import java.io.File;

public class PrintFiles {
    public static void main(String[] args) {
        File file = new File(".//src//ForClass");
        String[] list = file.list();
        if (list != null) {
            for (String s : list) {
                System.out.println(s);
            }
        }
    }
}
