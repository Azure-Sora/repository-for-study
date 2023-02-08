package ArrayListLearning.Student;

import java.util.ArrayList;
import java.util.Scanner;

public class Start {
    public static void main(String[] args) {
        ArrayList<Student> list = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            Student s = new Student(sc.next(), sc.nextInt());
            list.add(s);
        }
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i).getName() + list.get(i).getAge());
        }
    }

}
