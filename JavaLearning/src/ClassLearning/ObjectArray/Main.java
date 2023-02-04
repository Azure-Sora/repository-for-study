package ClassLearning.ObjectArray;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Cars[] allCars = new Cars[3];
        Cars c1 = new Cars();
        Cars c2 = new Cars();
        Cars c3 = new Cars();
        allCars[0] = c1;
        allCars[1] = c2;
        allCars[2] = c3;
        System.out.print("第一辆车的品牌是：");
        allCars[0].setBrand(sc.next());
        System.out.print("第一辆车的价格为：");
        allCars[0].setPrice(sc.nextInt());
        System.out.print("第一辆车的颜色是：");
        allCars[0].setColor(sc.next());
        System.out.println("第一辆车品牌是" + allCars[0].getBrand() + "，价格是" + allCars[0].getPrice() + "元，颜色是" + allCars[0].getColor());

    }

}
