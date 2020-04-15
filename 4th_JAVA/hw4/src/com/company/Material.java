package com.company;

public class Material {
    private String name;
    private boolean fragile;

    public Material(String name, boolean fragile){
        this.name = name;
        this.fragile = fragile;
    }

    public String name(){
        return name;
    }

    public boolean isFragile(){
        return fragile;
    }

    public String toString(){
        return "Name: " + name + "; Fragile: " + fragile + "; ";
    }
}
