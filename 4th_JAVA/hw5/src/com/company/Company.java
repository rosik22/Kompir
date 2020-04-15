package com.company;
import java.util.ArrayList;

public class Company {
    private String name;
    private int maxEmployees;
    private ArrayList<Employee> employees;

    //Constructor for Company class;
    public Company(String name, int maxEmployees){
        this.name = name;
        this.maxEmployees = maxEmployees;
        employees = new ArrayList<Employee>();
    }

    //method which adds the new employee into the list of all employees;
    public void hireEmployee(Employee employee){
        if(employees.size() < maxEmployees) {
            employees.add(employee);
        }
        else System.out.println("The company cannot hire anymore people.");
    }

    //method which removes an employee from the list of all employees;
    public void fireEmployee(Employee employee){
        if(employees.size() > 0){
            employees.remove(employee);
            System.out.println(employee.getName() + " has been fired.");
        }
        else System.out.println("Cannot fire anybody, because nobody is working for the company.");
    }

    //method to display all the hired employees;
    public void displayEmployees(){
        for(Employee employee : employees){
            System.out.println(employee.toString());
        }
    }

    //method which calculates the sum of the salaries of all employees;
    public double getAllSalaries(){
        double salaries = 0;
        for(Employee employee: employees){
            salaries += employee.getSalary();
        }
        return salaries;
    }

    //method which calculates the average wage of all employees;
    public double getAverageWage(){
        if(getAllSalaries() == 0) return 0;
        return getAllSalaries()/employees.size();
    }

    //method which is used to increase the bonus of an employee;
    public void increaseBonus(Employee employee,double percentage){
        employee.setBonus(percentage);
        System.out.println("The bonus of " + employee.getName() + " has been increased with " + percentage + "%.");
    }

    //method which is used to increase the bonus for all employees with specific number;
    public void increaseBonusForAll(double percentage){
        for(Employee employee: employees){
            employee.setBonus(percentage);
        }
        System.out.println("The bonus for all employees has been increased with " + percentage + "%.");
    }

    //method that calculates the average wage of all employees with a specific contract;
    public void getAverageOfContract(Contract contract){
        double salary = 0;
        int count = 0;
        for(Employee employee : employees) {
            if (employee.getContract() == contract){
                salary += employee.getSalary();
                count++;
            }
        }
        System.out.println("Average wage of employees with " + contract.name() +
               " contract is: " + salary/count);
    }

    //method which prints the basic data of the company;
    public void print(){
        System.out.println("Company name: (" + name +
                "), maximum number of employees: (" + maxEmployees +
                "), number of currently employed people: (" + employees.size() + ")");
    }

}
