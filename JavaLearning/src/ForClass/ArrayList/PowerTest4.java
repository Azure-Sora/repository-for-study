package ForClass.ArrayList;

public class PowerTest4 {
    public static void main(String[] args) {
        System.out.print("This program will raise the float ");
        System.out.println("numbers in an array to an integer power.");
        float[] basesToTest = { 1, 2, 3, 4};
        testPower(basesToTest, 2);
        testPower(basesToTest, 3);
        testPower(basesToTest, -2);
        testPower(basesToTest, 0);
    } // method main(String[])
    public static void testPower(float[] base, int exponent)
    {
        System.out.println();
        System.out.print("Raising the numbers in ");
        printArray(base);
        System.out.println(" to the " + exponent + " power:");
        double[] result = MathUtility.power(base, exponent);
        System.out.print(" The numbers in ");
        printArray(base);
        System.out.println(" to the " + exponent + " power are:");
        System.out.print(" ");
        printArray(result);
    } // method testPower
    public static void printArray(double[] numbers) {
        System.out.print("{");
        if ( numbers.length > 0 )
            System.out.print(" " + numbers[0]);
        for ( int i = 1; i < numbers.length; i++ )
            System.out.print(", " + numbers[i]);
        System.out.print(" }");
    } // method printArray(double[])
    public static void printArray(float[] numbers){
        System.out.print("{");
        if ( numbers.length > 0 )
            System.out.print(" " + numbers[0]);
        for ( int i = 1; i < numbers.length; i++ )
            System.out.print(", " + numbers[i]);
        System.out.print(" }");
    }
}
