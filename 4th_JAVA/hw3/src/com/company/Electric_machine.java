package com.company;

public class Electric_machine {
    private int minGuarantee;
    private Manufacturer manufacturer;
    private int price;

    public Electric_machine(Manufacturer manufacturer, int price, int minGuarantee){
        this.manufacturer = manufacturer;
        this.price = price;
        this.minGuarantee = minGuarantee;
    }

    public int getPrice(){
        return price;
    }

    public int getMinGuarantee(){
        return minGuarantee;
    }

    public String toString(){
        return manufacturer.toString() + "; Price: " + price + " dollars; Min Guarantee: (" + minGuarantee + " months)";
    }

    public int guaranteePeriod(){
        if(manufacturer.hasGuarantee() == true)
            return  minGuarantee + 12;
        return minGuarantee;
    }
}
