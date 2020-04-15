package com.company;

public class Shoes extends Item{
    private boolean tryOn;
    private double price;

    public Shoes(Box box, double ship_price,String address, boolean tryOn){
        super(box, ship_price,address);
        this.tryOn = tryOn;
    }

    @Override
    public String toString(){
        return super.toString()+ "Shipment price: " + String.format("%.2f",price) + "; Can you try them: " + tryOn + "; ";
    }

    @Override
    public double ShippingPrice(){
        price = ship_price*super.totalWeight();
        if(tryOn)
            return price += price*3/100;
        return price;
    }
}
