package com.company;

public class newThread implements Runnable {
    Thread t;
    newThread(){
        t = new Thread(this, "Simon");
        System.out.println("Child: " + t);
        t.start();
    }

    public void run(){
        try{
            for(int i=5; i>0; i--){
                System.out.println("Child: " + i);
                Thread.sleep(1000);
            }
        }catch (InterruptedException e){
            System.out.println("Child interrupted");
        }
        System.out.println("Child finished");
    }
}
