package com.company;

public class Client {
    private int budget;

    public Client(int budget){
        this.budget = budget;
    }

    public int getBudget(){
        return budget;
    }

    public void changeBudget(int price){
        if((budget - price) > 0)
            budget -= price;
        else
            budget = 0;
    }

    public String toString(){
        return "Budget: " + budget;
    }
}
