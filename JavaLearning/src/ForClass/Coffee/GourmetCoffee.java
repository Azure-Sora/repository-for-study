package ForClass.Coffee;//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by FernFlower decompiler)
//

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.util.Iterator;

public class GourmetCoffee {
    private static BufferedReader stdIn;
    private static PrintWriter stdOut;
    private static PrintWriter stdErr;
    private static final String DELIMITER = "_";
    private static final NumberFormat CURRENCY;
    private Catalog catalog;
    private Order currentOrder;
    private Sales sales;

    public static void main(String[] var0) throws IOException {
        GourmetCoffee var1 = new GourmetCoffee(load());
        var1.run();
    }

    private static Catalog load() {
        Catalog var0 = new Catalog();
        var0.addProduct(new Coffee("C001", "Colombia, Whole, 1 lb", 17.99, "Colombia", "Medium", "Rich and Hearty", "Rich", "Medium", "Full"));
        var0.addProduct(new Coffee("C002", "Colombia, Ground, 1 lb", 18.75, "Colombia", "Medium", "Rich and Hearty", "Rich", "Medium", "Full"));
        var0.addProduct(new Coffee("C003", "Italian Roasts, Whole, 1 lb", 16.8, "Latin American Blend", "Italian Roast", "Dark and heavy", "Intense", "Low", "Medium"));
        var0.addProduct(new Coffee("C004", "Italian Roasts, Ground, 1 lb", 17.55, "Latin American Blend", "Italian Roast", "Dark and heavy", "Intense", "Low", "Medium"));
        var0.addProduct(new Coffee("C005", "French Roasts, Whole, 1 lb", 16.8, "Latin American Blend", "French Roast", "Bittersweet, full intense", "Intense, full", "None", "Medium"));
        var0.addProduct(new Coffee("C006", "French Roasts, Ground, 1 lb", 17.55, "Latin American Blend", "French Roast", "Bittersweet, full intense", "Intense, full", "None", "Medium"));
        var0.addProduct(new Coffee("C007", "Guatemala, Ground, 1 lb", 17.99, "Guatemala", "Medium", "Rich and complex", "Spicy", "Medium to high", "Medium to full"));
        var0.addProduct(new Coffee("C008", "Guatemala, Ground, 1 lb", 18.75, "Guatemala", "Medium", "Rich and complex", "Spicy", "Medium to high", "Medium to full"));
        var0.addProduct(new Coffee("C009", "Guatemala, Whole, 1 lb", 19.99, "Sumatra", "Medium", "Vibrant and powdery", "Like dark chocolate", "Gentle", "Rich and full"));
        var0.addProduct(new Coffee("C010", "Guatemala, Ground, 1 lb", 20.5, "Sumatra", "Medium", "Vibrant and powdery", "Like dark chocolate", "Gentle", "Rich and full"));
        var0.addProduct(new Coffee("C011", "Special Blend, Whole, 1 lb", 16.8, "Latin American Blend", "Dark roast", "Full, roasted flavor", "Hearty", "Bold and rich", "Full"));
        var0.addProduct(new Coffee("C012", "Special Blend, Ground, 1 lb", 17.55, "Latin American Blend", "Dark roast", "Full, roasted flavor", "Hearty", "Bold and rich", "Full"));
        var0.addProduct(new CoffeeBrewer("B001", "Home Coffee Brewer", 150.0, "Brewer 100", "Pourover", 6));
        var0.addProduct(new CoffeeBrewer("B002", "Coffee Brewer, 2 Warmers", 200.0, "Brewer 200", "Pourover", 12));
        var0.addProduct(new CoffeeBrewer("B003", "Coffee Brewer, 3 Warmers", 280.0, "Brewer 210", "Pourover", 12));
        var0.addProduct(new CoffeeBrewer("B004", "Commercial Brewer, 20 cups", 380.0, "Quick Coffee 100", "Automatic", 20));
        var0.addProduct(new CoffeeBrewer("B005", "Commercial Brewer, 40 cups", 480.0, "Quick Coffee 200", "Automatic", 40));
        var0.addProduct(new Product("A001", "Almond Flavored Syrup", 9.0));
        var0.addProduct(new Product("A002", "Irish Creme Flavored Syrup", 9.0));
        var0.addProduct(new Product("A003", "Mint Flavored syrup", 9.0));
        var0.addProduct(new Product("A004", "Caramel Flavored Syrup", 9.0));
        var0.addProduct(new Product("A005", "Gourmet Coffee Cookies", 12.0));
        var0.addProduct(new Product("A006", "Gourmet Coffee Travel Thermo", 18.0));
        var0.addProduct(new Product("A007", "Gourmet Coffee Ceramic Mug", 8.0));
        var0.addProduct(new Product("A008", "Gourmet Coffee 12 Cup Filters", 15.0));
        var0.addProduct(new Product("A009", "Gourmet Coffee 36 Cup Filters", 45.0));
        return var0;
    }

    private GourmetCoffee(Catalog var1) {
        this.catalog = var1;
        this.currentOrder = new Order();
        this.sales = new Sales();
    }

    private void run() throws IOException {
        for(int var1 = this.getChoice(); var1 != 0; var1 = this.getChoice()) {
            if (var1 == 1) {
                this.displayCatalog();
            } else if (var1 == 2) {
                this.displayProductInfo();
            } else if (var1 == 3) {
                this.displayOrder();
            } else if (var1 == 4) {
                this.addModifyProduct();
            } else if (var1 == 5) {
                this.removeProduct();
            } else if (var1 == 6) {
                this.saleOrder();
            } else if (var1 == 7) {
                this.displayOrdersSold();
            }
        }

    }

    private int getChoice() throws IOException {
        while(true) {
            try {
                stdErr.println();
                stdErr.print("[0]  Quit\n[1]  Display catalog\n[2]  Display product\n[3]  Display current order\n[4]  Add|modify product to|in current order\n[5]  Remove product from current order\n[6]  Register sale of current order\n[7]  Display sales\nchoice> ");
                stdErr.flush();
                int var1 = Integer.parseInt(stdIn.readLine());
                stdErr.println();
                if (0 <= var1 && 7 >= var1) {
                    return var1;
                }

                stdErr.println("Invalid choice:  " + var1);
            } catch (NumberFormatException var3) {
                stdErr.println(var3);
            }
        }
    }

    private void displayCatalog() {
        int var1 = this.catalog.getNumberOfProducts();
        if (var1 == 0) {
            stdErr.println("The catalog is empty");
        } else {
            Iterator var2 = this.catalog.getIterator();

            while(var2.hasNext()) {
                Product var3 = (Product)var2.next();
                stdOut.println(var3.getCode() + " " + var3.getDescription());
            }
        }

    }

    private void displayProductInfo() throws IOException {
        Product var1 = this.readProduct();
        if (var1 != null) {
            stdOut.println("  Description: " + var1.getDescription());
            stdOut.println("  Price: " + var1.getPrice());
            if (var1 instanceof Coffee) {
                Coffee var2 = (Coffee)var1;
                stdOut.println("  Origin: " + var2.getOrigin());
                stdOut.println("  Roast: " + var2.getRoast());
                stdOut.println("  Flavor: " + var2.getFlavor());
                stdOut.println("  Aroma: " + var2.getAroma());
                stdOut.println("  Acidity: " + var2.getAcidity());
                stdOut.println("  Body: " + var2.getBody());
            } else if (var1 instanceof CoffeeBrewer) {
                CoffeeBrewer var3 = (CoffeeBrewer)var1;
                stdOut.println("  Model: " + var3.getModel());
                stdOut.println("  Water Supply: " + var3.getWaterSupply());
                stdOut.println("  Number of Cups: " + var3.getNumberOfCups());
            }
        } else {
            stdErr.println("There are no products with that code");
        }

    }

    private void displayOrder() {
        int var1 = this.currentOrder.getNumberOfItems();
        if (var1 == 0) {
            stdErr.println("The current order is empty");
        } else {
            Iterator var2 = this.currentOrder.getIterator();

            while(var2.hasNext()) {
                stdOut.println(((OrderItem)var2.next()).toString());
            }

            stdOut.println("Total: " + CURRENCY.format(this.currentOrder.getValue()));
        }

    }

    private void addModifyProduct() throws IOException {
        Product var1 = this.readProduct();
        if (var1 != null) {
            int var2 = this.readQuantity();
            OrderItem var3 = this.currentOrder.getItem(var1);
            if (var3 == null) {
                this.currentOrder.addItem(new OrderItem(var1, var2));
                stdOut.println("The product " + var1.getCode() + " has been added");
            } else {
                var3.setQuantity(var2);
                stdOut.println("The quantity of the product " + var1.getCode() + " has been modified");
            }
        } else {
            stdErr.println("There are no products with that code");
        }

    }

    private void removeProduct() throws IOException {
        Product var1 = this.readProduct();
        if (var1 != null) {
            OrderItem var2 = this.currentOrder.getItem(var1);
            if (var2 != null) {
                this.currentOrder.removeItem(var2);
                stdOut.println("The product " + var1.getCode() + " has been removed from the current order");
            } else {
                stdErr.println("There are no products in the current order with that code");
            }
        } else {
            stdErr.println("There are no products with that code");
        }

    }

    private void saleOrder() {
        if (this.currentOrder.getNumberOfItems() > 0) {
            this.sales.addOrder(this.currentOrder);
            this.currentOrder = new Order();
            stdOut.println("The sale of the order has been registered");
        } else {
            stdErr.println("The current order is empty");
        }

    }

    private void displayOrdersSold() {
        int var1 = this.sales.getNumberOfOrders();
        if (var1 != 0) {
            int var2 = 1;
            Iterator var3 = this.sales.getIterator();

            while(var3.hasNext()) {
                Order var4 = (Order)var3.next();
                stdOut.println("Order " + var2++);
                Iterator var5 = var4.getIterator();

                while(var5.hasNext()) {
                    stdOut.println("   " + ((OrderItem)var5.next()).toString());
                }

                stdOut.println("   Total: " + CURRENCY.format(var4.getValue()));
            }
        } else {
            stdErr.println("There are no sales");
        }

    }

    private Product readProduct() throws IOException {
        stdErr.print("Product code> ");
        stdErr.flush();
        return this.catalog.getProduct(stdIn.readLine());
    }

    private int readQuantity() throws IOException {
        while(true) {
            try {
                stdErr.print("Quantity> ");
                stdErr.flush();
                int var1 = Integer.parseInt(stdIn.readLine());
                if (var1 > 0) {
                    return var1;
                }

                stdErr.println("Invalid input. Please enter a positive integer");
            } catch (NumberFormatException var3) {
                stdErr.println(var3);
            }
        }
    }

    static {
        stdIn = new BufferedReader(new InputStreamReader(System.in));
        stdOut = new PrintWriter(System.out, true);
        stdErr = new PrintWriter(System.err, true);
        CURRENCY = NumberFormat.getCurrencyInstance();
    }
}
