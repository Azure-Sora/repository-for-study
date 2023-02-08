package ArrayListLearning.User;

import java.util.ArrayList;
import java.util.Scanner;

public class UserTest {
    public static void main(String[] args) {
        ArrayList<User> list = new ArrayList<>();
        User u1 = new User("114514", "tiansuo", "123456");
        User u2 = new User("1919", "dechuan", "112233");
        User u3 = new User("810", "chunping", "111111");
        list.add(u1);
        list.add(u2);
        list.add(u3);
        Scanner sc = new Scanner(System.in);
        System.out.print("ID:");
        System.out.println(searchForID(sc.next(), list));
    }

    public static int searchForID(String idLookingFor, ArrayList<User> list) {
        for (int i = 0; i < list.size(); i++) {
            if (idLookingFor.equals(list.get(i).getId())) {
                return i;
            }
        }
        return -1;
    }
}
