package ForClass.ArrayList;

import java.lang.reflect.Array;

public class ResizeArray {
    /**
     * 为一个新数组分配新空间，并将原来数组的内容拷贝到新数组中去
     *
     * @param oldArray the old array, to be reallocated. 原来的数组，将被重新分配空间
     * @param newSize  the new array size.新数组的大小
     * @return A new array with the same contents. 存放原来数组内容的新数组
     */
    private static Object resizeArray(Object oldArray, int newSize) {
        int oldSize = java.lang.reflect.Array.getLength(oldArray);
        Class elementType = oldArray.getClass().getComponentType();
        Object newArray = java.lang.reflect.Array.newInstance(
                elementType, newSize);
        int preserveLength = Math.min(oldSize, newSize);
        if (preserveLength > 0)
            System.arraycopy(oldArray, 0, newArray, 0, preserveLength);
        return newArray;
    }

    /**
     * 为一个二维数组分配新空间，并将原来数组的内容拷贝到新数组中去
     *
     * @param old2DArray    the old array, to be reallocated.
     * @param newRowSize    row size of the new array
     * @param newColumnSize column size of the new array.
     * @return A new array
     */
    private static Object resize2DArray(Object old2DArray, int newRowSize, int newColumnSize) {
        int oldRowSize = Array.getLength(old2DArray);
        int oldColumnSize = Array.getLength(Array.get(old2DArray, 0));
        Class elementType = old2DArray.getClass().getComponentType().getComponentType();
        Object new2DArray = Array.newInstance(elementType, newRowSize, newColumnSize);
        int preserveRowLength = Math.min(oldRowSize, newRowSize);
        int preserveColumnLength = Math.min(oldColumnSize, newColumnSize);
        if (preserveRowLength > 0 && preserveColumnLength > 0) {
            for (int i = 0; i < preserveRowLength; i++) {
                System.arraycopy(Array.get(old2DArray, i), 0, Array.get(new2DArray, i), 0, preserveColumnLength);
            }
        }
        return new2DArray;
    }

    public static void main(String[] args) {
        int[] testArray = {1, 2, 3};
        testArray = (int[]) resizeArray(testArray, 5);
        testArray[3] = 4;
        testArray[4] = 5;
        for (int element : testArray)
            System.out.print(element + " ");
        System.out.println("\n");

        int test2DArray[][] = {{1, 2, 3}, {4, 5, 6}};
        test2DArray = (int[][]) resize2DArray(test2DArray, 5, 10);
        for (int[] row : test2DArray) {
            for (int element : row)
                System.out.print(element + " ");
            System.out.println();
        }
    }

}

