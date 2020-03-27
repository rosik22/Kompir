package com.company;

public class Director {
    private String directorName;
    private int directorAge;

    /*
        constructor that sets the director's name and age;
     */
    public Director(String directorName, int directorAge){
        this.directorName = directorName;
        this.directorAge = directorAge;
    }

    /*
        method that returns the director's name;
     */
    public String getDirectorName(){
        return directorName;
    }

    /*
        method that returns the director's age;
     */
    public int getDirectorAge(){
        return directorAge;
    }
}