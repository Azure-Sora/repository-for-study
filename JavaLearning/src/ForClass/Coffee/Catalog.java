package ForClass.Coffee;

import java.util.Iterator;
import java.util.Vector;

public class Catalog {
    private Vector<Product> products = new Vector<>();

    public Catalog() {
    }

    public void addProduct(Product var1) {
        this.products.add(var1);
    }

    public Iterator getIterator() {
        return this.products.iterator();
    }

    public Product getProduct(String var1) {
        Iterator var2 = this.getIterator();

        Product var3;
        do {
            if (!var2.hasNext()) {
                return null;
            }

            var3 = (Product)var2.next();
        } while(!var3.getCode().equals(var1));

        return var3;
    }

    public int getNumberOfProducts() {
        return this.products.size();
    }
}
