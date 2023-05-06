package ForClass.ArrayList;

public class Matrix {
    public static void main(String[] args) {
        int[][] matrixA = {{1, 0, 1},
                {1, 2, 3},
                {1, 4, 5}};
        int[][] matrixB = {{5, 4, 0},
                {4, 8, 1},
                {1, 1, 0}};
        System.out.println("The product of the matrices is:");
        printMatrix(multiply(matrixA, matrixB));


    }

    public static int[][] multiply(int[][] a, int[][] b) {
        int[][] result = new int[a.length][b[0].length];
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < b[0].length; j++)
                for (int k = 0; k < a[0].length; k++)
                    result[i][j] += a[i][k] * b[k][j];
        return result;
    }

    public static void printMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++)
                System.out.print(" " + matrix[i][j]);
            System.out.println();
        }
    }
}
