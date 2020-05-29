public class Main {

    public static void main(String[] args) throws Exception {
		Shop lidl = new Shop("Lidl");
		Shop kaufland = new Shop("Kaufland");

	    Goods yogurt = new Goods(1275, "Yogurt", 0.85, "10.07.2020");
		Goods cheese = new Goods(232, "Cheese", 2.85, "15.07.2020");
		Goods bread = new Goods(2233, "Bread", 1.00, "10.07.2020");
		Goods spaghetti = new Goods(2233, "Spaghetti", 1.30, "30.10.2021");
		Goods pickles = new Goods(2233, "Pickles", 1.90, "25.12.2021");
		Goods sushi = new Goods(2233, "Sushi", 1.90, "02.07.2020");
		Goods pork = new Goods(2233, "Pork", 1.90, "09.07.2020");
		
		lidl.addGoods(yogurt,45);
		lidl.addGoods(cheese,15);
		lidl.addGoods(bread, 30);
		lidl.addGoods(spaghetti, 25);
		lidl.addGoods(pickles, 15);

		kaufland.addGoods(cheese, 35);
		kaufland.addGoods(yogurt, 20);
		kaufland.addGoods(bread, 40);
		kaufland.addGoods(sushi, 10);
		kaufland.addGoods(pork, 50);
		kaufland.addGoods(spaghetti, 40);

	    Cashier Anna = new Cashier(2321, "Anna");
	    Cashier Boiko = new Cashier(2323, "Boiko");
	    Cashier Rumen = new Cashier(2324, "Rumen");

		lidl.addCashiers(Anna);
		lidl.addCashiers(Boiko);
		kaufland.addCashiers(Rumen);

		Cash_register cr = new Cash_register(Anna, "1");
		Cash_register cr1 = new Cash_register(Boiko, "2");
		Cash_register cr2 = new Cash_register(Rumen, "3");

		lidl.addCashRegisters(cr1);
		kaufland.addCashRegisters(cr2);

		//Shows the case where you try to buy from a register which
		//is not located in this shop
		try{
			lidl.sellGoods(cr);
		}catch(Exception e){
			System.out.println(e);
		}

		lidl.addCashRegisters(cr);

		try{
			lidl.sellGoods(cr);
		}catch(Exception e){
			System.out.println(e);
		}

		try{
			lidl.sellGoods(cr1);
		}catch(Exception e){
			System.out.println(e);
		}

		try{
			lidl.sellGoods(cr);
		}catch(Exception e){
			System.out.println(e);
		}

		System.out.println("\nThe total revenue for " + lidl.getName() +" is: " + String.format("%.2f", lidl.getRevenue()));

    }
}
