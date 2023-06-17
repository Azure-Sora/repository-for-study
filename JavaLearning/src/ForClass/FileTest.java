package ForClass;

import java.io.*;

public class FileTest {
    public static void main(String[] args) {
        PrintWriter stdout = new PrintWriter(System.out);
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        File file = new File("fileTest.txt");
        try {
            if (!file.exists()) {
                file.createNewFile();
            } else {
                file.delete();
                file.createNewFile();
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        try {
            FileWriter fw = new FileWriter(file);
            for (; ; ) {
                String input = stdin.readLine();
                if (input.equals("")) {
                    break;
                }
                fw.write(input + "\n");
                fw.flush();
            }
            fw.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        try {
            /*Scanner sc = new Scanner(new FileReader(file));
            while (sc.hasNext()) {
                System.out.println(sc.nextLine());
            }*/
            BufferedReader br = new BufferedReader(new FileReader(file));
            while (br.ready()) {
                System.out.println(br.readLine());
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
