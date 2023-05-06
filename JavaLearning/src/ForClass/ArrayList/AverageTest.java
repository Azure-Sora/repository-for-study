package ForClass.ArrayList;

public class AverageTest {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("This program will average any "
                    + "number of precision floating-point ");
            System.out.println("numbers entered as command-line "
                    + "arguments. Result should be zero");
            System.out.println("for no command-line arguments.");
        } // if
        double[] numbers = new double[args.length];
        for ( int i = 0; i < args.length; i++ )
            numbers[i] = Double.parseDouble(args[i]);
        System.out.println("The average is " + MathUtility.average(numbers) + ".");
    } // method main
}
