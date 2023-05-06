package ArrayListLearning;

public class GenericTest {
    public static void main(String[] args) {

    }
    public static <E> void printArray(E[] src)
    {
        for (E e : src) {
            System.out.println(e);
        }
    }
}

