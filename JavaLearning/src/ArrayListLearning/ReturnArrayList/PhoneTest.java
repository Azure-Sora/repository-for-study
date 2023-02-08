package ArrayListLearning.ReturnArrayList;

import java.util.ArrayList;
import java.util.Scanner;

public class PhoneTest {
    public static void main(String[] args) {
        ArrayList<Phone> list = new ArrayList<>();
        Phone p1 = new Phone("小米", 1999);
        Phone p2 = new Phone("苹果", 8999);
        Phone p3 = new Phone("OPPO", 2999);
        list.add(p1);
        list.add(p2);
        list.add(p3);
        Scanner sc = new Scanner(System.in);
        System.out.print("价格：");
        ArrayList<Phone> phonePriceUnder;
        phonePriceUnder = phonePriceUnder(list, sc.nextInt());
        for (int i = 0; i < phonePriceUnder.size(); i++) {
            System.out.printf("%s，%d\n", phonePriceUnder.get(i).getBrand(), phonePriceUnder.get(i).getPrice());
        }
    }

    public static ArrayList<Phone> phonePriceUnder(ArrayList<Phone> list, int price) {
        ArrayList<Phone> result = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getPrice() <= price) {
                result.add(list.get(i));
            }
        }
        return result;
    }
}
