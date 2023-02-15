import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        boolean running = true;
        ArrayList<Admin> list = new ArrayList<>();
        String choice;
        while (running) {
            System.out.println("欢迎来到学生管理系统");
            System.out.println("请选择操作 1.登录 2.注册 3.忘记密码 4.退出系统");
            Scanner sc = new Scanner(System.in);
            choice = sc.next();
            switch (choice) {
                case "1" -> {
                    signIn(list);
                    running = false;
                }
                case "2" -> signUp(list);
                case "3" -> forgetPassword(list);
                case "4" -> running = false;
                default -> System.out.println("没有该功能！");
            }
        }

    }

    public static void forgetPassword(ArrayList<Admin> list) {
        Scanner sc = new Scanner(System.in);
        String userName;
        String id;
        String phoneNumber;
        System.out.print("请输入用户名：");
        userName = sc.next();
        int index = searchForAdmin(list, userName);
        if (index == -1) {
            System.out.println("用户名未注册，请先注册！");
            return;
        }
        System.out.print("请输入身份证号：");
        id = sc.next();
        System.out.print("请输入电话号码：");
        phoneNumber = sc.next();
        if (id.equals(list.get(index).getID()) && phoneNumber.equals(list.get(index).getPhoneNumber())) {
            while (true) {
                System.out.print("请输入修改后密码：");
                String password = sc.next();
                System.out.print("请再次输入密码：");
                String passwordAgain = sc.next();
                if (password.equals(passwordAgain)) {
                    list.get(index).setPassword(password);
                    break;
                }
                System.out.println("两次输入不一致，请再次输入！");
            }
            System.out.println("修改成功！");
        } else {
            System.out.println("账号信息不匹配，修改失败！s");
        }

    }

    public static void signUp(ArrayList<Admin> list) {
        Scanner sc = new Scanner(System.in);
        Admin newAdmin = new Admin();
        while (true) {
            System.out.print("请输入用户名：");
            String userName = sc.next();
            if (isUserNameLegal(userName)) {
                newAdmin.setUserName(userName);
                break;
            }
            System.out.println("用户名长度必须在3~15位之间，只能是字母加数字的组合，不能是纯数字！");
        }
        while (true) {
            System.out.print("请输入密码：");
            String password = sc.next();
            System.out.print("请再次输入密码：");
            String passwordAgain = sc.next();
            if (password.equals(passwordAgain)) {
                newAdmin.setPassword(password);
                break;
            }
            System.out.println("两次输入不一致，请再次输入！");
        }
        while (true) {
            System.out.print("请输入身份证号：");
            String id = sc.next();
            if (isIDLegal(id)) {
                newAdmin.setID(id);
                break;
            }
            System.out.println("身份证号不合法，请再次输入！");
        }
        while (true) {
            System.out.print("请输入电话号码：");
            String phoneNumber = sc.next();
            if (isPhoneNumberLegal(phoneNumber)) {
                newAdmin.setPhoneNumber(phoneNumber);
                break;
            }
            System.out.println("电话号码不合法，请再次输入！");
        }
        list.add(newAdmin);
        System.out.println("注册成功！");
    }

    public static void signIn(ArrayList<Admin> list) {
        Scanner sc = new Scanner(System.in);
        String userName;
        String password;
        String code;
        System.out.print("请输入用户名：");
        userName = sc.next();
        int index = searchForAdmin(list, userName);
        if (index == -1) {
            System.out.println("用户名未注册，请先注册！");
            return;
        }
        System.out.print("请输入密码：");
        password = sc.next();
        while (true) {
            String rightCode = generateCode();
            System.out.println(rightCode);
            System.out.print("请输入验证码：");
            code = sc.next();
            if (code.equals(rightCode)) {
                break;
            }
            System.out.println("验证码错误，请再次输入！");
        }
        int tryCount = 0;
        while (tryCount < 3) {
            if (tryCount != 0) {
                System.out.print("请输入密码：");
                password = sc.next();
            }
            tryCount++;
            if (password.equals(list.get(index).getPassword())) {
                ManageSystem.manageSystem();
                return;
            }
            System.out.printf("密码错误，还有%d次机会！\n", 3 - tryCount);
        }
        System.out.println("登陆失败！");

    }

    public static int searchForAdmin(ArrayList<Admin> list, String userName) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getUserName().equals(userName)) {
                return i;
            }
        }
        return -1;
    }

    public static boolean isUserNameLegal(String userName) {
        if (userName.length() >= 3 && userName.length() <= 15) {
            for (int i = 0; i < userName.length(); i++) {
                if (!(userName.charAt(i) >= '0' && userName.charAt(i) <= '9')) {
                    for (int i1 = 0; i1 < userName.length(); i1++) {
                        char c = userName.charAt(i1);
                        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                            return false;
                        }
                    }
                    return true;
                }
            }
            return false;
        }
        return false;
    }

    public static boolean isIDLegal(String id) {
        if (id.length() == 18) {
            if (id.charAt(0) == '0') {
                return false;
            }
            for (int i = 0; i < id.length() - 1; i++) {
                char c = id.charAt(i);
                if (!(c >= '0' && c <= '9')) {
                    return false;
                }
            }
            char c = id.charAt(17);
            if ((c >= '0' && c <= '9') || c == 'x' || c == 'X') {
                return true;
            }
            return false;
        }
        return false;
    }

    public static boolean isPhoneNumberLegal(String phoneNumber) {
        if (phoneNumber.length() == 11) {
            if (phoneNumber.charAt(0) == '0') {
                return false;
            }
            for (int i = 0; i < phoneNumber.length(); i++) {
                char c = phoneNumber.charAt(i);
                if (!(c >= '0' && c <= '9')) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    public static String generateCode() {
        StringBuilder sb = new StringBuilder();
        Random rd = new Random();
        sb.append(rd.nextInt(10));
        for (int i = 0; i < 4; i++) {
            switch (rd.nextInt(2)) {
                case 0 -> sb.append((char) (rd.nextInt('a', 'z' + 1)));
                case 1 -> sb.append((char) (rd.nextInt('A', 'Z' + 1)));
            }
        }
        char[] code = sb.toString().toCharArray();
        for (int i = 0; i < code.length; i++) {
            int index = rd.nextInt(5);
            char temp = code[i];
            code[i] = code[index];
            code[index] = temp;
        }
        return new String(code);
    }
}

