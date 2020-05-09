package com.company.hotel;

public class InsufficientNumberOfRoomsException extends Exception {
    private final int numberOfRooms;

    public InsufficientNumberOfRoomsException(int numberOfRooms){
        this.numberOfRooms = numberOfRooms;
    }

    public int getNumberOfRooms(){
        return numberOfRooms;
    }

    public String toString(){
        return  "InsufficientNumberOfRoomsException{ " +
                "numberOfRooms: " + numberOfRooms + " }";
    }
}
