package com.company;

import javax.print.Doc;
import java.time.Period;

public class Repository {
    private double capacity;
    private int numberOfDocuments;
    private double currentSize;

    public Repository(double capacity){
        this.capacity = capacity;
        numberOfDocuments = 0;
        currentSize = 0;
    }

    public double getCapacity() { return capacity;}

    public void setCapacity() {
        if (capacity > 0){
            this.capacity = capacity;
        }
    }

    public int getNumberOfDocuments() { return numberOfDocuments;}

    public double getCurrentSize() { return currentSize;}

    public void addDocument (Document document){
        if(document.getSize() <= (capacity - currentSize)){
            numberOfDocuments ++;
            currentSize += document.getSize();
            System.out.println(document.toString());
        }
        else {
            System.out.println("Not enough space!");
        }
    }

    public void removeDocument (Document document){
        numberOfDocuments --;
        currentSize -= document.getSize();
    }

    public String toString(){
        return "capacity: " + capacity + "; number of documents: " + numberOfDocuments + "; current size: " + currentSize;
    }
}
