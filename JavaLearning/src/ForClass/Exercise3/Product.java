package ForClass.Exercise3;

public class Product {

    public Product() {
    }

    public Product(String initialCode, String initialDescription,
                   double initialPrice) {
        this.code = initialCode;
        this.description = initialDescription;
        this.price = initialPrice;
    }


    private String code;


    public String getCode() {
        return code;
    }


    private String description;


    public String getDescription() {
        return description;
    }


    private Double price;


    public Double getPrice() {
        return price;
    }

    public boolean equals(Object object) {
        if (object instanceof Product) {
            if (this.code.equalsIgnoreCase(((Product) object).getCode()))
                return true;
        }

        return false;

    }

    public String toString() {
        return code + "_" + description + "_" + price;

    }

}
