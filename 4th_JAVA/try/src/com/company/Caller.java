package com.company;

public class Caller implements Runnable {
    String msg;
    Thread t;
    Callme target;
    public Caller(String s, Callme target){
        this.target = target;
        msg = s;
        t = new Thread(this);
        t.start();
    }
    public void run(){
        synchronized (target) {
            target.call(msg);
        }
    }
}
