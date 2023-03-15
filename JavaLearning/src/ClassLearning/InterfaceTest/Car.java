package ClassLearning.InterfaceTest;

public class Car implements MoveHome{
    @Override
    public void moveHome() {
        System.out.println("车来搬家了");
    }
}
