package com.company;

public class Stove extends Electric_machine{
    private boolean gas = false;
    private boolean electrical = false;

    public Stove(Manufacturer manufacturer, int price,int minGuarantee, String type){
        super(manufacturer,price,minGuarantee);
        if(type == "gas")
            this.gas = true;
        else if (type == "electrical")
            this.electrical = true;
    }

    public int getPrice(){
        return super.getPrice();
    }

    @Override
    public String toString(){
        if(gas == true)
            return super.toString() + "; Type: gas stove";
        return super.toString() + "; Type: electrical stove";
    }

    @Override
    public int guaranteePeriod(){
        if(gas == true)
            return super.guaranteePeriod() + 12;
        else
            return super.guaranteePeriod();
    }
}
