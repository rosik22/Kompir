package com.company;

public class Box {

    double width;
    double height;
    double depth;

    public Box() {
    }

    public Box(double width, double height, double depth) {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    double volume() {
        return this.width * this.height * this.depth;
    }

    void increaseDimensions(double increaseNumber) throws IllegalArgumentException{
        if(increaseNumber <0 || increaseNumber>100){
            throw new IllegalArgumentException("The value must be between 0 and 100 but it's " + increaseNumber);
        }
        else{
            this.width += this.width * increaseNumber /100;
            this.height += this.height * increaseNumber /100;
            this.depth += this.depth * increaseNumber /100;
        }
    }

    void optionalIncreaseDimensions(double increaseNumber, double volumeNumber){
        try{
            if(volume() <= volumeNumber){
                increaseDimensions(increaseNumber);
            }
        } catch (IllegalArgumentException e){
            System.err.println("Caught: " + e);
        }
    }

    @Override
    public String toString(){
        return "box.Box{ width: " + width +
                ", height: " + height +
                ", depth: " + depth + " }";
    }
}