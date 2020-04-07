package com.company;

public class Main {

    public static void main(String[] args) {
        Shop shop1 = new Shop();
	    Manufacturer manufacturer1 = new Manufacturer("James", true);

	    //creating gas stove
	    Stove stove1 = new Stove(manufacturer1, 200, 12, "gas");
	    Stove stove2 = new Stove(manufacturer1, 250, 10, "electrical");
	    Client Jessica = new Client(300);
	    Client Kenny = new Client(400);

	    shop1.Buy(Jessica,stove1);
	    shop1.Buy(Kenny,stove2);

	    Washing_machine washing_machine1 = new Washing_machine(manufacturer1, 300, 10, 2000, true);
		Washing_machine washing_machine2 = new Washing_machine(manufacturer1, 220, 12, 3000, false);
	    Client John = new Client(300);
	    Client Maria = new Client(300);

	    shop1.Buy(John,washing_machine1);
	    shop1.Buy(Maria,washing_machine2);

	    Manufacturer manufacturer2 = new Manufacturer("Boris", false);
	    Electric_machine electric_machine1 = new Electric_machine(manufacturer2, 200, 12);
		Electric_machine electric_machine2 = new Electric_machine(manufacturer2, 220, 10);
	    Client Peter = new Client(300);
	    Client Zak = new Client(150);

	    shop1.Buy(Peter, electric_machine1);
	    shop1.Buy(Zak,electric_machine2);

	    System.out.println("Jessica has " + Jessica.getBudget() + " dollars left");
		System.out.println("Kenny has " + Kenny.getBudget() + " dollars left");
		System.out.println("John has " + John.getBudget() + " dollars left");
		System.out.println("Maria has " + Maria.getBudget() + " dollars left");
		System.out.println("Peter has " + Peter.getBudget() + " dollars left");
		System.out.println("Zak has " + Zak.getBudget() + " dollars left");
    }
}
