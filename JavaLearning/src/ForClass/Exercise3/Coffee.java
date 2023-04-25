package ForClass.Exercise3;


public class Coffee extends Product {

    public Coffee(String initialCode, String initialDescription,
                  double initialPrice, String initialOrigin, String initialRoast,
                  String initialFlavor, String initialAroma, String initialAcidity,
                  String initialBody) {
        super(initialCode, initialDescription, initialPrice);
        this.origin = initialOrigin;
        this.roast = initialRoast;
        this.flavor = initialFlavor;
        this.aroma = initialAroma;
        this.acidity = initialAcidity;
        this.body = initialBody;
    }


    private String origin;

    public String getOrigin() {
        return origin;
    }

    private String roast;

    public String getRoast() {
        return roast;
    }

    private String flavor;

    public String getFlavor() {
        return flavor;
    }

    private String aroma;

    public String getAroma() {
        return aroma;
    }

    private String acidity;

    public String getAcidity() {
        return acidity;
    }


    private String body;


    public String getBody() {
        return body;
    }


    public String toString() {
        return super.getCode() + "_" + super.getDescription() + "_" + super.getPrice() + "_" + origin + "_" + roast + "_" + flavor + "_" + aroma + "_" + acidity + "_" + body;
    }

}
