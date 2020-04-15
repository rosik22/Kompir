package com.company;

public class Furniture extends Item{
    private String brand;
    private double price;

    public Furniture(Box box, double ship_price, String address, String brand){
        super(box,ship_price,address);
        this.brand = brand;
    }

    @Override
    public String toString(){
        return super.toString() + "Shipment price: " + String.format("%.2f",price) + "; Brand: " + brand + "; ";
    }

    @Override
    public double ShippingPrice(){
        double volume1 = box.volume();
        price = ship_price * super.totalWeight();
        if(isFragile() && (volume1 > 24000)) {
            price += price * 1.5 / 100;
        }
        return price;
    }
}
