package com.company;

public class Box {
    private double width, height, length;

    public Box(double width, double height, double length){
        this.width = width;
        this.height = height;
        this.length = length;
    }

    public double volume(){
        return width*height*length;
    }

    public String toString(){
        return "width: " + width + ", height: " + height + ", length: " + length + "; ";
    }
}
