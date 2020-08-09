import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Shop {
    private String name;
    private Map<Goods, Integer> listOfGoods;
    private ArrayList<Cashier> cashiers;
    private static int countOfReceipts;
    private double revenue = 0;
    private List<File> receiptList = new ArrayList<>();
    private List<Cash_register> cashRegisters = new ArrayList<>();

    public Shop(String name) {
        this.name = name;
        listOfGoods = new HashMap<Goods, Integer>();
        cashiers = new ArrayList<Cashier>();
    }

    public String getName() {
        return name;
    }

    public void addCashRegisters(Cash_register register) {
        cashRegisters.add(register);
    }

    public void addGoods(Goods goods, int quantity) {
        listOfGoods.put(goods, quantity);
    }

    public void addCashiers(Cashier cashier) {
        cashiers.add(cashier);
    }

    //creates the shopping list; takes the ingredients from the terminal;
    public Map<Goods, Integer> getClientGroceries() throws IOException {
        Map<Goods, Integer> clientGroceriesList = new HashMap<Goods, Integer>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        int num;
        boolean check;
        do {
            check = false;
            /* try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            } */
            System.out.print("\n(end to stop) Enter the product you're looking for: ");
            str = br.readLine();
            if (str.equals("end"))
                break;

            for (Map.Entry<Goods, Integer> g : listOfGoods.entrySet()) {
                if (g.getKey().getName().equalsIgnoreCase(str)) {
                    System.out.print("Enter the product quantity: ");
                    num = Integer.parseInt(br.readLine());
                    clientGroceriesList.put(g.getKey(), num);
                    check = true;
                }
            }
            if (check != true)
                System.out.println("There is no such product in the shop\n");
        } while (!str.equals("end"));
        return clientGroceriesList;
    }

    //checks if the ingredient is present in the shop; 
    //if it is - the register is started as a thread;
    public void sellGoods(Cash_register cash_register) throws Exception {
        if (cashRegisters.contains(cash_register)) {
            Map<Goods, Integer> goods = new HashMap<Goods, Integer>();
            goods = getClientGroceries();
            
            cash_register.addToRegister(goods);
            cash_register.start();

            for (Map.Entry<Goods, Integer> g : goods.entrySet()) {
                int quantity = g.getValue();
                if (listOfGoods.get(g.getKey()) - quantity >= 0) {
                    listOfGoods.put(g.getKey(), listOfGoods.get(g.getKey()) - quantity);
                } else {
                    goods.remove(g.getKey());
                    throw new Exception("Not enough quantity of the product (" + g.getKey().getName() + "); Needed "
                            + (quantity - listOfGoods.get(g.getKey())) + " more.");
                }

            }
            calculateRevenue(goods);
            receiptList.add(cash_register.getReceipt());
        }else{
            throw new Exception("Cannot achieve purchase because this cash register doesn't exist in this shop.");
        }
    }

    private void calculateRevenue(Map<Goods, Integer> goods) {
        for (Map.Entry<Goods, Integer> g : goods.entrySet()) {
            revenue += g.getValue() * g.getKey().getPrice();
        }
    }

    public double getRevenue() {
        return revenue;
    }

    public int getCountOfReceipts() {
        countOfReceipts = Receipt.getNumberOfReceipts();
        return countOfReceipts;
    }
}
