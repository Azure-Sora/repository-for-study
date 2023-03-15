package ClassLearning.InterfaceTest;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("1.车；2.公司");
        Scanner sc = new Scanner(System.in);
        switch (sc.nextInt()) {
            case 1 -> moveHome(new Car());
            case 2 -> moveHome(new MovingCompany());
        }
    }

    public static void moveHome(MoveHome m) {
        m.moveHome();
    }
}
