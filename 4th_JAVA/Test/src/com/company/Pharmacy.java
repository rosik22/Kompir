package com.company;

import java.util.ArrayList;
public class Pharmacy {
    private double income = 0;
    private ArrayList<Item> items;

    public Pharmacy(){
        items = new ArrayList<Item>();
    }

    public void addItem(Item item){
        items.add(item);
    }

    public void income(){
        for (Item item : items){
            income += item.totalPrice();
        }
        System.out.println("Total income of the pharmacy is: " + income);
    }

    public void printSpecificAge(Age_Category category){
        double partialIncome = 0;
        for(Item item : items){
            if(item.getCategory() == category)
                partialIncome += item.totalPrice();
        }
        System.out.println("Total income from items of age category " + category.name() + " is: " + partialIncome);
    }

    public void getItems(){
        for(Item item : items){
            System.out.println(item.toString());
        }
    }
}
