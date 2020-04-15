package com.company;

public abstract class Item {
    protected final int INVENTORYNUMBER;
    protected double defaultPrice;
    protected Age_Category category;

    public Item(int INVENTORYNUMBER, double defaultPrice, Age_Category category){
        this.INVENTORYNUMBER = INVENTORYNUMBER;
        this.defaultPrice = defaultPrice;
        this.category = category;
    }

    public Age_Category getCategory(){
        return category;
    }

    abstract public double totalPrice();

    public boolean suitableForChildren(Age_Category category){
        if(category.name() == "CHILDREN") return true;
        return false;
    }

    abstract public boolean compareItems(Item item2);

    public String toString(){
        return "Inventory number: (" + INVENTORYNUMBER +
                "), Default price: (" + defaultPrice +
                "), Age category: (" + category + ")";
    }
}
