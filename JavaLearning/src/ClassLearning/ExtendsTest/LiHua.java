package ClassLearning.ExtendsTest;

public class LiHua extends Cat{
    public void Touch(){
        System.out.println("摸摸");
    }
    public void show(){
        System.out.println(super.age);
    }
    @Override
    public void drinkWater(){
        System.out.println("喝水水");
    }
}
