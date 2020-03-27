package com.company;
import java.util.*;

public class Studio {
    private int workingHours = 8;
    private Vector clients = new Vector();

    public Studio(){}

    /*
        method used to rent a studio (if possible);
        also stores the clients in a vector;
     */
    public int rent(String client, int hours) {
        if (hours > workingHours){
            System.out.println("The studio is not available for " + hours +" hour/s");
            return 1;
        }
        else {
            workingHours -= hours;
            System.out.println("The studio has been rented for " + hours + " hour/s");
            clients.add(client);
            return 0;
        }
    }

    /*
       method that prints all the clients that rented the studio for the day;
     */
    public void printClients(){
        System.out.println("The clients that rented that studio are: " + clients);
    }
}
