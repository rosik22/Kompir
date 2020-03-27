package com.company;

import java.util.Vector;

public class MusicCompany {
    private String companyName;
    private final Director director;
    private Studio studio;
    private double earnings = 0;
    private double currentPrice = 10;
    private double defaultPrice = 10;
    private int revenueHr;

    /*
      constructor that sets the name of the company,
      the name of the director, his age
      and creates a studio in that company;
     */
    public MusicCompany(String companyName, Director director){
        this.director = director;
        this.companyName = companyName;
        Studio studio1 = new Studio();
        this.studio = studio1;
    }

    /*
      method that returns the company's name;
     */
    public String getCompanyName(){
        return companyName;
    }

    /*
        1)method that calls Studio method rent() which sets for how many hours a studio is rented (if possible);
     */
    public int rentStudio(String client,int hours){
        int answer = studio.rent(client,hours);
        if(answer == 0)
            revenueHr += hours;
        return answer;
    }

    /*
       2)method that sets the current rent price for the studio;
     */
    public void setPrice(double price){
        if(price >= defaultPrice) {
            currentPrice = price;
            System.out.println("the price has been set to " + currentPrice + " leva");
        }
        else {
            System.out.println("The price is lower than expected " +
                    "so it'll be set the default price of " + defaultPrice + " leva");
            currentPrice = defaultPrice;
        }
    }

    /*
       3)method that displays the daily earnings of a studio in leva;
     */
    public void checkEarnings(){
        earnings += revenueHr*currentPrice;
        revenueHr = 0;
        System.out.println("The earnings from that studio are " + earnings + " leva");
    }

    /*
       4)method that displays the daily earnings of a studio in euro and dollars;
     */
    public void checkEarningsEuroDollars(){
        if(earnings > 0) {
            double euro = earnings / 1.95583;
            System.out.println("Earnings in euro: " + String.format("%.2f",euro));
            double dollar = earnings / 1.78;
            System.out.println("Earnings in dollars: " + String.format("%.2f", dollar));
        }
        else System.out.println("Earnings are 0 euro; 0 dollars");
    }

    /*
       5)method which compares two companies by the renting price they offer;
     */
    public void compareCompanies(MusicCompany company2){
        if(this.currentPrice > company2.currentPrice)
            System.out.println("The first studio is more expensive.");
        else if(this.currentPrice < company2.currentPrice)
            System.out.println("The second studio is more expensive.");
        else
            System.out.println("Both studios offer the same price.");
    }

    /*
       6)method that reduces the price by a certain percentage;
     */
    public void percentageReduction(int percentage){
        currentPrice -= currentPrice*percentage/100;
        System.out.println("The price for an hour has been reduced with " + percentage + "% and now is " + currentPrice + " leva");
    }

    /*
       7)method which compares two companies by the age of their directors;
     */
    public void compareByDirectorAge(MusicCompany company2){
        if(this.director.getDirectorAge() > company2.director.getDirectorAge())
            System.out.println("The first studio's director is older than the second studio's director.");
        else
            System.out.println("The second studio's director is older than the first studio's director.");
    }

    /*
      method that prints the clients of the studio for the day;
     */
    public void printClients(){
        studio.printClients();
    }
}