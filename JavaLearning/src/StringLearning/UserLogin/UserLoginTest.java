package StringLearning.UserLogin;

import java.util.Scanner;

public class UserLoginTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String userName = "AoiSora";
        String password = "Color123";
        int tryCount = 0;
        while (tryCount < 3) {
            System.out.print("用户名：");
            String inputUserName = sc.next();
            System.out.print("密码：");
            String inputPassword = sc.next();
            if (inputUserName.equals(userName) && inputPassword.equals(password)) {
                System.out.println("登陆成功！");
                break;
            } else {
                System.out.println("用户名或密码错误！");
                tryCount++;
            }
        }
        if (tryCount == 3) {
            System.out.println("登陆失败！");
        }
    }
}
