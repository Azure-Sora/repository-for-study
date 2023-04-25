package ForClass.Exercise3;


public class CoffeeBrewer extends Product {

    public CoffeeBrewer(String initialCode, String initialDescription, double initialPrice, String initialModel, String initialWaterSupply, int initialNumberOfCups) {
        super(initialCode, initialDescription, initialPrice);
        model = initialModel;
        waterSupply = initialWaterSupply;
        numberOfCups = initialNumberOfCups;
    }

    private String model;


    public String getModel() {
        return model;
    }


    private String waterSupply;


    public String getWaterSupply() {
        return waterSupply;
    }


    private Integer numberOfCups;


    public Integer getNumberOfCups() {
        return numberOfCups;
    }


    public String toString() {
        return super.getCode() + "_" + super.getDescription() + "_" + super.getPrice() + "_" + model + "_" + waterSupply + "_" + numberOfCups;
    }

}
