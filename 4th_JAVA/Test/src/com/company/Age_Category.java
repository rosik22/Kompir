package com.company;

public enum Age_Category {
    ADULTS(15), TEENAGERS(10), CHILDREN(5);
    private double price;

    Age_Category(double price){
        this.price = price;
    }

    public double getPrice(){
        return price;
    }
}
