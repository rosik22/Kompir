public class Goods {
    private final double id;
    private final String name;
    private double price;
    private final String exp_date;

    public Goods(double id, String name, double price, String exp_date){
        this.id = id;
        this.name = name;
        this.price = price;
        this.exp_date = exp_date;
    }

    public double getId(){
        return id;
    }

    public String getName(){
        return name;
    }

    public double getPrice(){
        return price;
    }

    public String getExp_date() {
        return exp_date;
    }

    public void setPrice(double price) {
        this.price = price;
    }


    @Override
    public String toString(){
        return "{Name: " + name + ", Id: " + id +
                ", Price: " + price + ", Date of expiry: " + exp_date + "}";
    }
}
