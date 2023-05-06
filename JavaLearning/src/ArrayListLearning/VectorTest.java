package ArrayListLearning;

import java.util.Vector;

public class VectorTest {
    public static void main(String[] args) {
        Vector<Integer> v = new Vector<>();
        v.add(1);
        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.get(i));
        }
    }

}
