package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
	   /* int[] unicode = {1040,1041,1042};
	    String ust = new String(unicode,0,3);
	    System.out.println(ust);
	    System.out.println(ust.charAt(1));
        String s = "Now is the time for all good men " +
                "to come to the aid of their country.";
        System.out.println(s.lastIndexOf('t',10));

        BufferedReader br = new BufferedReader(new
                InputStreamReader(System.in));
        String str;
        System.out.println("Enter lines of text.");
        System.out.println("Enter 'stop' to quit.");
        do {
            str = br.readLine();
            System.out.println(str);
        } while(!str.equals("stop"));

        Scanner in = new Scanner(System.in);
        String first = in.nextLine();
        String last = in.nextLine();
        System.out.println(first + " " + last);

        //threads
        Thread t = Thread.currentThread();
        System.out.println("1: " + t);
        t.setName("Gosha");
        System.out.println("2: " + t);
        try{
            for(int i=5; i>0; i--){
                System.out.println(i);
                Thread.sleep(1000);
            }
        }catch (InterruptedException e){
            System.out.println("Interrupted");
        }


        new newThread();
        new newThread();
        new newThread();
        try{
            for(int i=5; i>0; i--){
                System.out.println("Main: " + i);
                Thread.sleep(1000);
            }
        }catch (InterruptedException e){
            System.out.println("Parent interrupted");
        }
        System.out.println("Parent finished");
        */
	   Callme c = new Callme();
	   Caller ob = new Caller("Blah",c);
	   Caller ob1 = new Caller("Blem", c);
	   Caller ob2 = new Caller("Blob", c);
	   try{
	       ob.t.join();
	       ob1.t.join();
	       ob2.t.join();
       }catch (InterruptedException e){
	       System.out.println("Ended");
       }

    }
}
