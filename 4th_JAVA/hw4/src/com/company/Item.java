package com.company;
import java.util.ArrayList;

public abstract class Item implements Shipment{
    protected Box box;
    protected String address;
    protected double ship_price;
    protected ArrayList<Element> elements = new ArrayList<Element>();

    public Item(Box box,double ship_price, String address){
        this.box = box;
        this.ship_price = ship_price;
        this.address = address;
    }

    public void addElement(Element element){
        elements.add(element);
    }

    public double totalWeight(){
        double weight = 0;
        if(!elements.isEmpty()){
            for(int i=0; i<elements.size(); i++){
                weight += elements.get(i).getWeight();
            }
        }
        return weight;
    }

    public void printElementList(){
        for(int i=0; i<elements.size(); i++){
            System.out.println(elements.get(i).toString());
        }
    }

    public boolean isFragile(){
        boolean check = false;
        for(int i=0; i<elements.size(); i++) {
            if (elements.get(i).isFragile()){
                check = true;
                break;
            }
        }
        return check;
    }

    public String toString(){
        return "Box: " + box + "Address: " + address + "; ";
    }

    @Override
    public abstract double ShippingPrice();
}
