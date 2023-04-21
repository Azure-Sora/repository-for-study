package ForClass.StudentAndTeacher;

import java.util.ArrayList;

public class Teacher extends Person{
    private String teacherID;
    private ArrayList<Student> students;
    private String subject;

    public Teacher(int age, String name, String gender, String teacherID, ArrayList<Student> students, String subject) {
        super(age, name, gender);
        this.teacherID = teacherID;
        this.students = students;
        this.subject = subject;
    }

    public String getTeacherID() {
        return teacherID;
    }

    public void setTeacherID(String teacherID) {
        this.teacherID = teacherID;
    }

    public ArrayList<Student> getStudents() {
        return students;
    }

    public void setStudents(ArrayList<Student> students) {
        this.students = students;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }
    public void teach(){
        System.out.println("老师教书");
    }
}
