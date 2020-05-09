import java.util.ArrayList;
import java.util.*;

public class Shop {
    private Map<Goods, Integer> listOfGoods;
    private ArrayList<Cashier> cashiers;
    private static int countOfReceipts;

    public Shop(){
        listOfGoods = new HashMap<Goods,Integer>();
        cashiers = new ArrayList<Cashier>();
    }

    public void addGoods(Goods goods, int quantity){
        listOfGoods.put(goods,quantity);
    }

    public void addCashiers(Cashier cashier){
        cashiers.add(cashier);
    }

    public void sellGoods(Map<Goods,Integer> goods, Cash_register cash_register) throws Exception{
        for(Map.Entry<Goods, Integer> g : goods.entrySet()) {
            if (listOfGoods.containsKey(g.getKey())) {
                int quantity = g.getValue();
                if (listOfGoods.get(g.getKey()) - quantity >= 0) {
                    listOfGoods.put(g.getKey(), listOfGoods.get(g.getKey()) - quantity);
                    System.out.println("Left: " + g.getKey().getName() + " x " + listOfGoods.get(g.getKey()));
                } else {
                    goods.remove(g.getKey());
                    throw new Exception("There is not enough quantity of the product: "
                            + g.getKey().getName() + ", Id:" + g.getKey().getId());
                }
            } else {
                System.out.println("There is no such product in the shop");
            }
        }
        cash_register.payForGoods(goods);
    }

    public double revenue(){
        return Receipt.getRevenue();
    }

    public int getCountOfReceipts(){
        countOfReceipts = Receipt.getNumberOfReceipts();
        return countOfReceipts;
    }
}
