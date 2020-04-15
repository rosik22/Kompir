package com.company;

public class Main {

    public static void main(String[] args) {
	Medicine medicine1 = new Medicine(2001, 20, Age_Category.CHILDREN, "Strepsils", false);
	Medicine medicine2 = new Medicine(2011, 15, Age_Category.ADULTS, "Muconasal", true);

	Pharmacy ph1 = new Pharmacy();
	ph1.addItem(medicine1);
	ph1.addItem(medicine2);

	ph1.income();
	ph1.printSpecificAge(Age_Category.ADULTS);

	medicine1.setHealthCarePercentage(20);

	ph1.income();
	ph1.printSpecificAge(Age_Category.CHILDREN);

	System.out.println("Is the first medicine more expensive than the second one? : " + medicine2.compareItems(medicine1));
	System.out.println(medicine2.compareMedicines(medicine1));
    }
}
