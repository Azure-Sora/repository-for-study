package ForClass.Coffee;//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by FernFlower decompiler)
//

import java.util.Iterator;
import java.util.Vector;

public class Order {
    private Vector<OrderItem> items = new Vector<>();

    public Order() {
    }

    public void addItem(OrderItem var1) {
        this.items.add(var1);
    }

    public void removeItem(OrderItem var1) {
        this.items.removeElement(var1);
    }

    public Iterator getIterator() {
        return this.items.iterator();
    }

    public OrderItem getItem(Product var1) {
        Iterator var2 = this.getIterator();

        OrderItem var3;
        do {
            if (!var2.hasNext()) {
                return null;
            }

            var3 = (OrderItem)var2.next();
        } while(!var3.getProduct().equals(var1));

        return var3;
    }

    public int getNumberOfItems() {
        return this.items.size();
    }

    public double getValue() {
        double var1 = 0.0;

        for(Iterator var3 = this.items.iterator(); var3.hasNext(); var1 += ((OrderItem)var3.next()).getValue()) {
        }

        return var1;
    }
}
