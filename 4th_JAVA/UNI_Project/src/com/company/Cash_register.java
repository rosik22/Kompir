import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Cash_register implements Runnable {
    private String name;
    private Cashier cashierOnShift;
    private double totalFromThePurchase;
    private File receipt;
    private ArrayList<Map<Goods, Integer>> allLists = new ArrayList<>();
    private Map<Goods, Integer> goods = new HashMap<>();
    private Thread t;
    private int count = 0;

    Cash_register(Cashier cashierOnShift, String name) {
        this.name = name;
        this.cashierOnShift = cashierOnShift;
    }

    public void setCashierOnShift(Cashier cashierOnShift) {
        this.cashierOnShift = cashierOnShift;
    }

    public Cashier getCashierOnShift() {
        return cashierOnShift;
    }

    public void addToRegister(Map<Goods, Integer> goodies) {
        allLists.add(goodies);
    }

    public File getReceipt() {
        return receipt;
    }

    public double getTotalFromThePurchase() {
        return totalFromThePurchase;
    }

    synchronized private void setGoods(){
        goods = allLists.get(count);
        count++;
    }

    public void run() {
        System.out.println("\nRunning \"" + name + "\"");
        try {
            System.out.println(Thread.currentThread());
            Thread.sleep(10000);
        } catch (InterruptedException e1) {
            e1.printStackTrace();
        }
        setGoods();
        for (Map.Entry<Goods, Integer> g : goods.entrySet()) {
            totalFromThePurchase += g.getKey().getPrice() * g.getValue();
        }
        try {
            Receipt rec = new Receipt(cashierOnShift);
            this.receipt = rec.createReceipt(goods, totalFromThePurchase);
        } catch (IOException e) {
            System.out.println("Something went wrong with creating the receipt.");
        }
        System.out.println("\"" + name + "\": " + cashierOnShift + "; Total: " + String.format("%.2f", totalFromThePurchase));

        System.out.println("\nThread \"" + name + "\" exiting");
    }

    public void start() {
        System.out.println("\nStarted \"" + name + "\"");
        t = new Thread(this);
        t.start();
    }
}
