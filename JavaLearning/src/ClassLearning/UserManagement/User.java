package ClassLearning.UserManagement;

public class User {
    private String name;
    private String password;
    private String address;
    private char gender;
    private int age;

    public User(){}
    public User(String name, String password, String address, char gender, int age) {
        this.name = name;
        this.password = password;
        this.address = address;
        this.gender = gender;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public char getGender() {
        return gender;
    }

    public void setGender(char gender) {
        this.gender = gender;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
