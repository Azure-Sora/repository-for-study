package ClassLearning.StaticTest;

public class ArrayUtilTest {
    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5, 6, 7};
        System.out.println(ArrayUtil.printAll(a));
        double[] b = {10.0, 20.0, 30.0};
        System.out.println(ArrayUtil.getAverage(b));
    }
}
