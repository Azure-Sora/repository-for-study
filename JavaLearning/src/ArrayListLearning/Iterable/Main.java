package ArrayListLearning.Iterable;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Client c = new Client(new ArrayList<>());
        c.getAccounts().add(new Account("A"));
        c.getAccounts().add(new Account("B"));
        c.getAccounts().add(new Account("C"));
        for (Account account : c) {
            System.out.println(account);
        }
    }
}
