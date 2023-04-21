package ForClass.StudentAndTeacher;

public class Student extends Person{
    public Student(int age, String name, String gender, String studentID, int grade, String inCLass) {
        super(age, name, gender);
        this.studentID = studentID;
        this.grade = grade;
        this.inCLass = inCLass;
    }

    private String studentID;
    private int grade;
    private String inCLass;

    public String getStudentID() {
        return studentID;
    }

    public void setStudentID(String studentID) {
        this.studentID = studentID;
    }

    public int getGrade() {
        return grade;
    }

    public void setGrade(int grade) {
        this.grade = grade;
    }

    public String getInCLass() {
        return inCLass;
    }

    public void setInCLass(String inCLass) {
        this.inCLass = inCLass;
    }
    public void study(){
        System.out.println("学生学习");
    }
}
