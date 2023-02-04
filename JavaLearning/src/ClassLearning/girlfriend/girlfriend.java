package ClassLearning.girlfriend;

public class girlfriend {
    private String name;
    private int age;
    private final char sex = '女';

    public girlfriend() {
    }

    public girlfriend(String name, int age) {
        setName(name);
        setAge(age);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setAge(int age) {
        if (age > 0 && age < 100) {
            this.age = age;
        } else {
            System.out.println("非法数据！");
        }
    }

    public int getAge() {
        return age;
    }

    public char getSex() {
        return sex;
    }

    public void love() {
        System.out.println("love!");
    }

    public void like() {
        System.out.println("すき!");
    }
}
