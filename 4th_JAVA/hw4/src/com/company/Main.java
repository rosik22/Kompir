package com.company;

public class Main {

    public static void main(String[] args) {
        Box box1 = new Box(50,50,50);
        Box box2 = new Box(30, 40,45);
        Material mat1 = new Material("textile", true);
        Material mat2 = new Material("leather", false);

        Element el1 = new Element(15, mat1);
        Element el2 = new Element(30, mat1);
        Element el3 = new Element(25, mat1);

        Element el_1 = new Element(2, mat2);
        Element el_2 = new Element(3, mat2);

	    Furniture fur1 = new Furniture(box1,1.5, "bl. Stamboliiski 64", "Videnov");
	    Shoes shoes1 = new Shoes(box2, 1, "bl. Bulgaria 85", true);


	    fur1.addElement(el1);
	    fur1.addElement(el2);
	    fur1.addElement(el3);

	    shoes1.addElement(el_1);
	    shoes1.addElement(el_2);

	    CourierCompany cc = new CourierCompany();

	    cc.addItem(fur1);
	    cc.addItem(shoes1);

	    cc.totalVolume();
	    cc.totalEarnings();
	    cc.toString();
    }
}
