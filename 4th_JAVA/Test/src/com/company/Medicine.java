package com.company;

public class Medicine extends Item{
    private String name;
    private double price;
    private boolean healthCare;
    private static int healthCarePercentage = 15;

    public Medicine(int INVENTORYNUMBER, double defaultPrice, Age_Category category,
                    String name, boolean healthCare){
        super(INVENTORYNUMBER, defaultPrice, category);
        this.name = name;
        this.healthCare = healthCare;
    }

    public void setHealthCarePercentage(int percentage){
        if(percentage > healthCarePercentage)
            healthCarePercentage = percentage;
        else System.out.println("Cannot change percentage, because new percentage is lower than the previous.");
    }

    @Override
    public double totalPrice(){
        price = defaultPrice+category.getPrice();
        if(healthCare == true) price -= price*healthCarePercentage/100;
        return price;
    }

    @Override
    public boolean compareItems(Item item2){
        if(this.totalPrice() > item2.totalPrice()) return true;
        return false;
    }

    public Medicine compareMedicines(Medicine med2){
        if(this.compareItems(med2) == true) return med2;
        return this;
    }

    @Override
    public String toString(){
        return super.toString() + ", Name: (" + name +
                "), Has health care discount: (" + healthCare + ")";
    }
}
