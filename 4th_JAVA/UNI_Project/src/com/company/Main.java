import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws Exception {
	    Shop lidl = new Shop();
	    Goods yogurt = new Goods(1275, "Yogurt", 0.85, "10.05.2020");
	    Goods cheese = new Goods(232, "Cheese", 2.85, "15.05.2020");
	    lidl.addGoods(yogurt,45);
	    lidl.addGoods(cheese,15);
	    Cashier Anna = new Cashier(2321, "Anna");
	    Cashier Boiko = new Cashier(2323, "Boiko");
	    Cashier Rumen = new Cashier(2324, "Rumen");

	    Cash_register cr = new Cash_register(Anna);

		lidl.addCashiers(Anna);
		lidl.addCashiers(Boiko);
		lidl.addCashiers(Rumen);

		System.out.println(lidl.getCountOfReceipts());

		Map<Goods,Integer> g1 = new HashMap<>();
		g1.put(yogurt,5);
		g1.put(cheese, 4);
		lidl.sellGoods(g1, cr);
		lidl.sellGoods(g1, cr);

		System.out.println(lidl.revenue());
    }
}
