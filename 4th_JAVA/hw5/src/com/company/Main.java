package com.company;

public class Main {

    public static void main(String[] args) {
        //Creating objects of type Employee;
        Employee em = new Employee("Georgi", 180);
        em.setContract(Contract.PERMANENT);
        Employee em1 = new Employee("Ivan", 180);
        em1.setContract(Contract.PART_TIME);
        Employee em2 = new Employee("Peter", 180);
        em2.setContract(Contract.TRAINEE);
        Employee em3 = new Employee("Martin", 180);
        em3.setContract(Contract.PERMANENT);

        //Creating object of type Company;
        Company com = new Company("Sony", 25);

        //Adding(hiring) employees to the company;
        com.hireEmployee(em);
        com.hireEmployee(em1);
        com.hireEmployee(em2);
        com.hireEmployee(em3);

        com.displayEmployees();

        com.increaseBonusForAll( 5);
        System.out.println("The sum of all salaries is: " + com.getAllSalaries());
        System.out.println("The average wage is: " + com.getAverageWage());
        com.increaseBonus(em, 5);

        com.fireEmployee(em1);

        com.getAverageOfContract(Contract.PERMANENT);

        com.print();
    }
}
