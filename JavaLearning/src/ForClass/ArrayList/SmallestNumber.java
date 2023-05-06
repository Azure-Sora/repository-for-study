package ForClass.ArrayList;

import javax.swing.*;

public class SmallestNumber {
    public static void main(String[] args) {
        int[] num = new int[10];
        int counter;
        int min = 0;
        int totalnumber = 3;
        for (counter = 0; counter < totalnumber; counter++) {
            num[counter] = Integer.parseInt(JOptionPane.showInputDialog(
                    "Enter numbers until " + totalnumber + " numbers are entered"));
            if ((counter == 0) || (num[counter] < min))
                min = num[counter];
        }
        JOptionPane.showMessageDialog(null,
                "The number with the smallest value is " + min);
    }
}
