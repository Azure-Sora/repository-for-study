package ClassLearning.UserManagement;

import java.util.Scanner;

public class UserTest {
    public static void main(String[] args) {
        User user1 = new User();
        Scanner sc = new Scanner(System.in);
        System.out.print("输入用户名：");
        user1.setName(sc.nextLine());
        System.out.println(user1.getName());
    }
}
