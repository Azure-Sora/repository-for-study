package ForClass.ArrayList;

public class ValueVsReference {
    public static void main(String[] args) {
        short[] a = {0, 2, 4, 6, 8};
        System.out.println("The values originally stored in the array are:");
        for (int i = 0; i < a.length; i++)
            System.out.print(" " + a[i]);
        System.out.println();
        System.out.println("Let's see how the values change.");
        modifyPrimitive(a[0]);
        for (int i = 0; i < a.length; i++)
            System.out.print(" " + a[i]);
        System.out.println(" Method tried to modify primitive element.");
        modifyArray(a);
        for (int i = 0; i < a.length; i++)
            System.out.print(" " + a[i]);
        System.out.println(" Method modified array.");
        modifyArrayReference(a);
        for (int i = 0; i < a.length; i++)
            System.out.print(" " + a[i]);
        System.out.println(" Method modified its own reference to array.");
    } // method main

    public static void modifyPrimitive(short p) {
        p = 20;
    } // method methodA

    public static void modifyArray(short[] b) {
        for (int j = 0; j < b.length; j++)
            b[j] = (short) (j * (-3));
    } // method modifyArray

    public static void modifyArrayReference(short[] b) {
        b = new short[5];
        for (int j = 0; j < b.length; j++)
            b[j] = (short) (j * 3);
    } // method modifyArrayReference
}
