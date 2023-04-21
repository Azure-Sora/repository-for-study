package ForClass.PersonAndEmployee;

public class Main {
    public static void main(String[] args) {
        Person person = new Person ("Joe Smith", "100 Main Ave");
        double salary = ((Employee) person).getSalary();
    }
}
