package com.company;

public class Newspaper extends Document{
    private String period;

    public Newspaper(String period, double size, String formatType, String title){
        super(size,formatType,title);
        this.period = period;
    }

    public String getPeriod(){
        return period;
    }

    @Override
    public String toString(){
        return super.toString() + " Newspaper{" + " period " + period + "}" ;
    }
}
