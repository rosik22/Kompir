package com.company;

public class Main {
    public static void main(String[] args) {
    	//start of triangle
	/*    Triangle triangle3 = new Triangle();
	    Triangle triangle2 = new Triangle(50);
	    Triangle triangle1 = new Triangle(3,4,5);

	    System.out.println(triangle1.toString());

	    System.out.println("is Triangle: " + triangle1.isTriangle());

	    System.out.println("The area is: " + (triangle1.area() * 100)/100);

	    triangle1.increaseSideLength(2);
	*/    //end of triangle

		//start of FlowerShop
		FlowerShop shop1 = new FlowerShop(3, 2);
		System.out.println(shop1.showFlowersShop());
		FlowerShop shop2 = new FlowerShop(4, 2);
		System.out.println("Are shop1's earnings bigger than shop2's? - " + shop1.checkBiggerEarnings(shop2));
		shop2.decreasePriceFlow(5);
		FlowerShop shop3 = shop1.shopWithMoreFlowers(shop2);
		System.out.println(shop1.earnings());
		System.out.println(shop2.earnings());
		System.out.println("The shop with more flowers has a: " + shop3.showFlowersShop());
    }
}
