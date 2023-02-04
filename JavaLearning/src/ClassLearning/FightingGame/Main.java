package ClassLearning.FightingGame;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean end = false;
        System.out.print("请输入角色1的名字：");
        String name = sc.nextLine();
        Character p1 = new Character(name, 100);
        System.out.print("请输入角色2的名字：");
        name = sc.nextLine();
        Character p2 = new Character(name, 100);
        while (!end) {
            int damage = p1.fight();
            end = p2.injure(damage);
            if (end) {
                continue;
            }
            damage = p2.fight();
            end = p1.injure(damage);
        }
        if (p1.getHealth() > 0) {
            System.out.println(p1.getName() + "打败了" + p2.getName());
        } else {
            System.out.println(p2.getName() + "打败了" + p1.getName());
        }
    }
}
