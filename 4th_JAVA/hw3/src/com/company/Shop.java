package com.company;

public class Shop {
    private Client client;
    private Electric_machine electric_machine;
    private Washing_machine washing_machine;
    private Stove stove;

    public Shop() {
    }

    public void Buy(Client client, Electric_machine electric_machine){
        this.client = client;
        this.electric_machine = electric_machine;
        if(electric_machine.getPrice() <= client.getBudget()) {
            client.changeBudget(electric_machine.getPrice());
            System.out.println("An electric machine with "+ electric_machine.toString() + " and " + electric_machine.guaranteePeriod() + " months guarantee has been purchased by this customer");
        }
        else
            System.out.println("The customer doesn't have enough money");
    }

    public void Buy(Client client, Stove stove) {
        this.client = client;
        this.stove = stove;
        if(stove.getPrice() <= client.getBudget()) {
            client.changeBudget(stove.getPrice());
            System.out.println("A stove with " + stove.toString() +" and " + stove.guaranteePeriod() + " months guarantee has been purchased by this customer");
        }
        else
            System.out.println("The customer doesn't have enough money");
    }

    public void Buy(Client client, Washing_machine washing_machine) {
        this.client = client;
        this.washing_machine = washing_machine;
        if(washing_machine.getPrice() <= client.getBudget()) {
            client.changeBudget(washing_machine.getPrice());
            System.out.println("A washing machine with "+ washing_machine.toString() + " and " + washing_machine.guaranteePeriod() + " months guarantee has been purchased by this customer");
        }
        else
            System.out.println("The customer doesn't have enough money");
    }

    public String toString(){
        return "This is a shop";
    }
}
