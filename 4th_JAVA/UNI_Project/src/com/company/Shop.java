import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

    public Map<Goods,Integer> clientList() throws IOException{
        Map<Goods,Integer> clientList = new HashMap<Goods,Integer>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;
        int num;
        boolean check;
		do{
            check = false;
            System.out.print("(end to stop) Enter the product you're looking for: ");
            str = br.readLine();
            if(str.equals("end")) break;
            
            for(Map.Entry<Goods, Integer> g : listOfGoods.entrySet()) {
                if(g.getKey().getName().equalsIgnoreCase(str)){
                    System.out.print("Enter the product quantity: ");
			        num = Integer.parseInt(br.readLine());
                    clientList.put(g.getKey(), num);
                    check = true;
                }
            }
            if(check!=true) System.out.println("There is no such product in the shop\n");
            else System.out.println();
        }while(!str.equals("end"));
        return clientList;
    }

    public void sellGoods(Cash_register cash_register) throws Exception{
        Map<Goods,Integer> goods = new HashMap<Goods,Integer>();
        goods = clientList();
        for(Map.Entry<Goods, Integer> g : goods.entrySet()) {
            int quantity = g.getValue();
            if (listOfGoods.get(g.getKey()) - quantity >= 0) {
                listOfGoods.put(g.getKey(), listOfGoods.get(g.getKey()) - quantity);
            } else {
                goods.remove(g.getKey());
                throw new Exception("Not enough quantity of the product ("
                        + g.getKey().getName() + "); Needed " + (quantity-listOfGoods.get(g.getKey())) + " more.");
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
