package com.company;

public class Element {
    private double weight;
    private Material material;

    public Element(double weight, Material material){
        this.weight = weight;
        this.material = material;
    }

    public boolean isFragile(){
        return material.isFragile();
    }

    public double getWeight(){
        return weight;
    }

    public String toString(){
        return "Weight: " + weight + "; Material: " + material.name() + "; ";
    }
}
