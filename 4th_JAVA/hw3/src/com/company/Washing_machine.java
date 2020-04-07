package com.company;

public class Washing_machine extends Electric_machine{
    private int cycles;
    private boolean dryer;

    public Washing_machine(Manufacturer manufacturer, int price,int minGuarantee, int cycles, boolean dryer){
        super(manufacturer,price,minGuarantee);
        this.cycles = cycles;
        this.dryer = dryer;
    }

    public int getPrice(){
        return super.getPrice();
    }

    @Override
    public String toString(){
        if (dryer == true)
            return super.toString() + "; Cycles: " + cycles + "; Has dryer";
        else
            return super.toString() + "; Cycles: " + cycles;
    }

    @Override
    public int guaranteePeriod(){
        if (dryer == true)
            return super.guaranteePeriod() + super.getMinGuarantee()/2;
        else
            return super.guaranteePeriod();
    }
}
