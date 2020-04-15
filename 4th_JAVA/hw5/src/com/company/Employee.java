package com.company;

public class Employee {
    private String name;
    private static int numberOfEmployees = 0;
    private int id;
    private Contract contract;
    private double hoursInMonth;
    private double salary;
    private double bonus;

    //Constructor of class Employee;
    public Employee(String name, double hoursInMonth){
        this.name = name;
        this.hoursInMonth = hoursInMonth;
        numberOfEmployees++;
        this.id = numberOfEmployees;
    }

    //method that returns the employee name;
    public String getName(){
        return name;
    }

    //method that sets the employee contract (which can be changed whenever);
    public void setContract(Contract contract){
        this.contract = contract;
        this.bonus = contract.getHourlyPayment() - 5;
    }

    //method that returns the current contract of an employee;
    public Contract getContract(){
        return contract;
    }

    //method which changes the bonus for an employee;
    public void setBonus(double bonus){
        this.bonus += bonus;
    }

    //method that returns the salary of an employee;
    public double getSalary(){
        this.salary = hoursInMonth*contract.getHourlyPayment();
        if(bonus == 0) return salary;
        return salary += salary*bonus/100;
    }

    //method that prints the basic data of an employee;
    public String toString(){
        return "Name: " + name + ", Id: " + id +
                ", Hours worked this month: " + hoursInMonth +
                ", Contract: " + contract.name();
    }
}
