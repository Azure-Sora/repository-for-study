package ForClass.PersonAndEmployee;

public class Person {
    /* Name of the person */
    private String  name;

    /* Address of the person */
    private String  address;

    /**
     * Constructs a <code>Person</code> object.
     *
     * @param initialName  the name of the person.
     * @param initialAddress  the address of the person.
     */
    public Person (String initialName, String initialAddress) {

        name = initialName;
        address = initialAddress;
    }

    /**
     * Returns the name of this person.
     *
     * @return the name of this person.
     */
    public String getName() {

        return this.name;
    }

    /**
     * Returns the address of this person.
     *
     * @return the address of this person.
     */
    public String getAddress() {

        return this.address;
    }

}
