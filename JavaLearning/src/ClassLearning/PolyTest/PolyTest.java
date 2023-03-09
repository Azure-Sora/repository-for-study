package ClassLearning.PolyTest;

public class PolyTest {
    public static void main(String[] args) {
        Person a = new Student();
        //a.studentMethod();
        a.personMethod();
        if (a instanceof Student b) {
            b.studentMethod();
        }
    }
}