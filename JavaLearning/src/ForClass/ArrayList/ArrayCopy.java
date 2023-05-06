package ForClass.ArrayList;

public class ArrayCopy {
    public static void main(String[] argv) {
// create a new integer array
        int N = 12; // length of array
        int[] array1 = new int[N];
        System.out.print("array1 = ");
// assign some arbitrary values to the array elements
        for (int i = 0; i < array1.length; i++) {
            array1[i] = i * i;
        }
// print the array
        for (int i = 0; i < array1.length; i++) {
            System.out.print(array1[i] + " ");
        }
        System.out.println("");
// Create a copy (?) of array1 and print it out
        System.out.print("array2 = ");
        int[] array2 = array1; // "copy" the array in one go
        for (int i = 0; i < array2.length; i++) {
            System.out.print(array2[i] + " ");
        }
        System.out.println("");
// Create a copy (?) of array1 individual elements and print it out
        System.out.print("array3 = ");
        int[] array3 = new int[array1.length];
        for (int i = 0; i < array3.length; i++) {
            array3[i] = array1[i]; // copy element by element
            System.out.print(array3[i] + " "); // print new array
        }
        System.out.println("");
// Modify an element of array1 and see what else changes.
        System.out.println("Changing array1[3] to 999 ...");
        array1[3] = 999;
        System.out.println("array1[3] = " + array1[3]);
        System.out.println("array2[3] = " + array2[3]);
        System.out.println("array3[3] = " + array3[3]);
    }
}
