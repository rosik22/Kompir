package com.company;

public enum Contract {
    PERMANENT(15), PART_TIME(10), TRAINEE(5);
    double hourlyPayment;

    Contract(double hourlyPayment){
        this.hourlyPayment = hourlyPayment;
    }

    public double getHourlyPayment(){
        return hourlyPayment;
    }
}
