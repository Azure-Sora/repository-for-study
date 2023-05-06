package ForClass.ArrayList;

//MathUtility.java
public class MathUtility {
    public static double power(float base, int exponent) {
        if (exponent < 0) {
            exponent = 0 - exponent;
            base = 1 / base;
        }  // if exponent < 0

        double product = 1;
        for (int i = 0; i < exponent; i++)
            product *= base;
        return product;
    }  // method power(float, int)

    public static long power(int base, int exponent) {
        if (exponent < 0) {
            System.err.println("错误: MathUtility.power(int, int) "
                    + "不能处理指数 "
                    + exponent + " < 0.");
            System.err.println("要求非负指数 "
                    + "返回长整型值。");
            return 0;
        }  // if exponent < 0

        long product = 1;
        for (int i = 0; i < exponent; i++)
            product *= base;
        return product;
    }  // method power(int, int)

    public static double[] power(float[] base, int exponent) {
        double[] result = new double[base.length];
        for (int i = 0; i < base.length; i++)
            result[i] = power(base[i], exponent);
        return result;
    }  // method power(float[], int)


    public static double average(double[] src) {
        double sum = 0;
        if (src.length == 0) {
            System.err.println("不能处理空数组.");
            return 0;
        }
        for (int i = 0; i < src.length; i++)
            sum += src[i];
        return sum / src.length;
    }  // method average(double[])
}  // class MathUtility
