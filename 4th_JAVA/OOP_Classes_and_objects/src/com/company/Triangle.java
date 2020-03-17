package com.company;

public class Triangle {
    private double side1;
    private double side2;
    private double side3;

    public Triangle() {
        this.side1 = 100;
        this.side2 = 100;
        this.side3 = 100;
    }

    public Triangle (double side){
        this.side1 = this.side2 = this.side3 = side;
    }

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    @Override
    public String toString() {
        return "Triangle{" +
                "side1=" + side1 +
                ", side2=" + side2 +
                ", side3=" + side3 +
                '}';
    }

    public boolean isTriangle(){
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }

    public double perimeter(){
        return side1+side2+side3;
    }

    public double area(){
        return Math.sqrt(perimeter()/2 * (perimeter()/2 - side1) * (perimeter()/2 - side2) * (perimeter()/2 - side3));
    }

    public void increaseSideLength(double num){
        if(num < 0){
            System.out.println("Not valid");
        }
        else{
            this.side1 += num;
            this.side2 += num;
            this.side3 += num;
        }
    }

    public boolean isEquilateral(){
        return side1 == side2 && side1 == side3;
    }

    public boolean isRectangular(){
        boolean isRect = (Math.pow(side1, 2) == Math.pow(side2, 2) + Math.pow(side3, 2)) || (Math.pow(side2, 2) == Math.pow(side1, 2) + Math.pow(side3, 2)) || (Math.pow(side3, 2) == Math.pow(side2, 2) + Math.pow(side1, 2));
        return isRect;
    }
}
