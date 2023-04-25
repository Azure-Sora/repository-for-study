package ForClass.Exercise3;


public class OrderItem {

    public OrderItem(Product initialProduct, int initialQuantity) {
        quantity = initialQuantity;
        product = initialProduct;
    }

    private Integer quantity;


    public Integer getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer newQuantity) {
        this.quantity = newQuantity;
    }


    public Double getValue() {
        return quantity * (product.getPrice());
    }


    public String toString() {
        return quantity + " " + product.getCode() + " " + product.getPrice();
    }


    private Product product = new Product();


    public Product getProduct() {
        return product;
    }


}
