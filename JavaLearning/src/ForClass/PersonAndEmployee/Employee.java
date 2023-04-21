package ForClass.PersonAndEmployee;

public class Employee extends Person {
    /* Salary of the employee */
    private double salary;

    /**
     * Constructs an <code>Employee</code> object.
     *
     * @param initialName  the name of the employee.
     * @param initialAddress  the address of the employee.
     * @param initialSalary  the salary of the employee.
     */
    public Employee (String initialName, String initialAddress,
                     double initialSalary) {

        super(initialName, initialAddress);
        salary = initialSalary;
    }

    /**
     * Returns the salary of this employee.
     *
     * @return the salary of this employee.
     */
    public double getSalary() {

        return this.salary;
    }

    /**
     * Modifies the salary of this employee.
     *
     * @param newSalary  the new salary.
     */
    public void setSalary(double newSalary) {

        salary = newSalary;
    }

}
