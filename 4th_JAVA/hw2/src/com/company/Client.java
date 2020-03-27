package com.company;

public class Client {
    private int hoursRented = 0;
    private String clientName;
    private String companyRented;

    /*
      constructor for Client that sets the client's name;
     */
    public Client(String clientName){
        this.clientName = clientName;
    }

    /*
      method that returns the client's name
     */
    public String getClientName(){
        return clientName;
    }

    /*
      method that returns the hours in which the client rented a studio;
     */
    public int getHoursRented(){
        return hoursRented;
    }

    /*
      method that allows a client to rent a studio (if possible)
     */
    public void rentCompany(MusicCompany companyRented, int hoursRented){
        int answer = companyRented.rentStudio(this.clientName, hoursRented);
        if(answer == 0){
            this.hoursRented = hoursRented;
            this.companyRented = companyRented.getCompanyName();
        }
    }

    /*
      method that prints what company's studio has been rented by that client;
     */
    public void rentedCompany(){
        if (companyRented == null)
            System.out.println("There is no studio rented by that person.");
        else
            System.out.println("This client rented a studio from the company " + companyRented);
    }
}
