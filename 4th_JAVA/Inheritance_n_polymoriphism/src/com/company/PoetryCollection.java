package com.company;

public class PoetryCollection extends Book{
    private int numberOfPoems;

    public PoetryCollection(double size, String formatType, String title, Author author, String ISBN, int numberOfPoems){
        super(size,formatType,title,author,ISBN);
        this.numberOfPoems = numberOfPoems;
    }

    public int getNumberOfPoems() { return numberOfPoems;}

    @Override
    public String toString(){
        return super.toString() + "PoetryCollection{" + " numberOfPoems " + numberOfPoems + "}";
    }
}
