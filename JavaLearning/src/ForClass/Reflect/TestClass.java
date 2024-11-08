package ForClass.Reflect;

public class TestClass {
    public TestClass() {};
    public TestClass(int a, String b) {
        this.a = a;
        this.b = b;
    }

    private int a;
    public String b;

    public int getI() {
        return 5;
    }

    public int getA() {
        return a;
    }

    public void setA(int a) {
        this.a = a;
    }
}
