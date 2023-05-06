package ArrayListLearning.Iterable;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Spliterator;
import java.util.function.Consumer;

public class Client implements Iterable<Account>{

    private ArrayList<Account> accounts = new ArrayList<>();

    public Client(ArrayList<Account> accounts) {
        this.accounts = accounts;
    }

    public ArrayList<Account> getAccounts() {
        return accounts;
    }

    public void setAccounts(ArrayList<Account> accounts) {
        this.accounts = accounts;
    }

    @Override
    public Iterator<Account> iterator() {
        return this.accounts.iterator();
    }

    @Override
    public void forEach(Consumer<? super Account> action) {
        Iterable.super.forEach(action);
    }

    @Override
    public Spliterator<Account> spliterator() {
        return Iterable.super.spliterator();
    }
}
