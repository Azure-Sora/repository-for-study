import java.util.ArrayList;
import java.util.Scanner;

public class ManageSystem {
    public static void manageSystem() {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> stuList = new ArrayList<>();
        String choice;
        boolean running = true;
        while (running) {
            System.out.println("-------------欢迎来到学生管理系统----------------");
            System.out.println("1：添加学生");
            System.out.println("2：删除学生");
            System.out.println("3：修改学生");
            System.out.println("4：查询学生");
            System.out.println("5：退出");
            System.out.print("请输入您的选择:");
            choice = sc.next();
            switch (choice) {
                case "1" -> addStudent(stuList);
                case "2" -> removeStudent(stuList);
                case "3" -> setStudent(stuList);
                case "4" -> printAll(stuList);
                case "5" -> running = false;
                default -> System.out.println("没有该功能！");
            }
        }
    }

    public static void addStudent(ArrayList<Student> list) {

        Scanner sc = new Scanner(System.in);
        System.out.println("添加学生：");
        Student newStu = new Student();
        System.out.print("请输入ID：");
        newStu.setId(sc.next());
        System.out.print("请输入姓名：");
        newStu.setName(sc.next());
        System.out.print("请输入年龄：");
        newStu.setAge(sc.nextInt());
        System.out.print("请输入家庭住址：");
        newStu.setAddress(sc.next());
        if (searchForStudent(list, newStu.getId()) == -1) {
            list.add(newStu);
            System.out.println("添加成功");
        } else {
            System.out.println("ID重复，添加失败");
        }
    }

    public static void removeStudent(ArrayList<Student> list) {
        Scanner sc = new Scanner(System.in);
        System.out.print("要删除的ID：");
        String id = sc.next();
        int index = searchForStudent(list, id);
        if (index == -1) {
            System.out.println("ID不存在");
        } else {
            list.remove(index);
            System.out.println("删除成功");
        }
    }

    public static void setStudent(ArrayList<Student> list) {
        Scanner sc = new Scanner(System.in);
        System.out.print("要修改的ID");
        String id = sc.next();
        int index = searchForStudent(list, id);
        if (index == -1) {
            System.out.println("ID不存在");
        } else {
            Student newStu = new Student();
            newStu.setId(id);
            System.out.print("请输入修改后姓名：");
            newStu.setName(sc.next());
            System.out.print("请输入修改后年龄：");
            newStu.setAge(sc.nextInt());
            System.out.print("请输入修改后家庭住址：");
            newStu.setAddress(sc.next());
            list.set(index, newStu);
            System.out.println("修改成功");
        }
    }


    public static void printAll(ArrayList<Student> list) {
        System.out.println("ID\t姓名\t年龄\t家庭住址");
        for (int i = 0; i < list.size(); i++) {
            System.out.printf("%8s%8s%8d%8s\n", list.get(i).getId(), list.get(i).getName(), list.get(i).getAge(), list.get(i).getAddress());
        }
    }

    public static int searchForStudent(ArrayList<Student> list, String id) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getId().equals(id)) {
                return i;
            }
        }
        return -1;
    }
}

