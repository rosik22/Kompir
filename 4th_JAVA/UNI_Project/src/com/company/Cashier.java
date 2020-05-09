public class Cashier {
    private final double id;
    private final String name;

    public Cashier(double id, String name){
        this.id = id;
        this.name = name;
    }

    public double getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString(){
        return "Cashier {Name: " + name + ", ID: " + id + "}";
    }
}
