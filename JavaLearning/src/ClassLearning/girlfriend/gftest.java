package ClassLearning.girlfriend;

public class gftest {
    public static void main(String[] args) {
        girlfriend mahiru = new girlfriend();
        mahiru.setAge(18);
        mahiru.setName("mahiru");
        mahiru.like();
        mahiru.love();
        System.out.println(mahiru.getAge());
        System.out.println(mahiru.getName());
        girlfriend keqing = new girlfriend("keqing",18);
        System.out.println(keqing.getName());
        System.out.println(keqing.getAge());
    }
}
