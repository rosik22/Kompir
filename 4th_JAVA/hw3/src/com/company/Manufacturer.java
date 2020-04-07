package com.company;

import javax.swing.table.TableColumn;

public class Manufacturer {
    private String manName;
    private boolean guarantee;

    public Manufacturer(String manName, boolean guarantee){
        this.manName = manName;
        this.guarantee = guarantee;
    }

    public boolean hasGuarantee(){
        if(guarantee == true)
            return true;
        return false;
    }

    public String toString(){
        if (guarantee == true)
            return "Manufacturer: " + manName + " who provides 12 months guarantee";
        return "Manufacturer: " + manName + " who does not provide guarantee";
    }
}
