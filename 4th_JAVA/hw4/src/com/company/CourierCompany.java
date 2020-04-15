package com.company;
import java.util.*;

public class CourierCompany {
    private ArrayList<Item> items = new ArrayList<Item>();

    public void addItem(Item furniture){
        items.add(furniture);
    }

    public void totalEarnings(){
        double earnings = 0;
        for(int i=0; i<items.size(); i++){
            earnings += items.get(i).ShippingPrice();
        }
        System.out.println("Total earnings: " + String.format("%.2f",earnings));
    }

    public void totalVolume(){
        double weight = 0;
        for(int i=0; i<items.size(); i++){
            weight += items.get(i).totalWeight();
        }
        System.out.println("Total weight: " + weight + " kg");
    }

    public String toString(){
        for(int i=0; i<items.size(); i++){
            System.out.println(items.get(i).toString());
        }
        return "";
    }
}
