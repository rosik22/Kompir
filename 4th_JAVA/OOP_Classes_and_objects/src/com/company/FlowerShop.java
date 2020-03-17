package com.company;

import java.util.concurrent.Flow;

public class FlowerShop {
    private int numberOfFlowers;
    private  double priceOfFlowers;

    public FlowerShop(){
        this.numberOfFlowers = 0;
        this.priceOfFlowers = 0;
    }

    public FlowerShop(int num){
        this.numberOfFlowers = num;
        this.priceOfFlowers = 0;
    }

    public FlowerShop(double num){
        this.numberOfFlowers = 0;
        this.priceOfFlowers = num;
    }

    public FlowerShop(int numFlowers, double priceFlowers){
        this.numberOfFlowers = numFlowers;
        this.priceOfFlowers = priceFlowers;
    }

    public String showFlowersShop(){
        return "number of flowers - " + numberOfFlowers + "; price for one flower - " + priceOfFlowers + ";" ;
    }

    public void increaseNumFlow(int num){
        if(num < 0) System.out.println("Invalid number");
        else this.numberOfFlowers += num;
    }

    public void decreaseNumFlow(int num){
        if(num < 0) System.out.println("Invalid number");
        else if(this.numberOfFlowers <= num){
            this.numberOfFlowers = 0;
        }
        else this.numberOfFlowers -= num;
    }

    public void increasePriceFlow(double price){
        if(price < 0) System.out.println("Invalid price");
        else this.priceOfFlowers += price;
    }

    public void decreasePriceFlow(double price){
        if(price < 0) System.out.println("Invalid price");
        else if(this.priceOfFlowers <= price){
            this.priceOfFlowers = 0;
        }
        else this.priceOfFlowers -= price;
    }

    public double earnings(){
        return priceOfFlowers * numberOfFlowers;
    }

    public boolean checkBiggerEarnings(FlowerShop shop2){
        return this.earnings() > shop2.earnings();
    }

    public FlowerShop shopWithMoreFlowers(FlowerShop shop2){
        if(this.numberOfFlowers > shop2.numberOfFlowers){
            return new FlowerShop(this.numberOfFlowers, this.priceOfFlowers);
        }
        else{
            return new FlowerShop(shop2.numberOfFlowers, shop2.priceOfFlowers);
        }
    }
}
