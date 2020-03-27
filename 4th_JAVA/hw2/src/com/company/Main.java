package com.company;

public class Main {

    public static void main(String[] args) {
        //creating director for the first company
        Director director1 = new Director("Ivan", 35);
        //creating the first company and setting its current rental price for the studio;
        MusicCompany company1 = new MusicCompany("City", director1);
        company1.setPrice(30);

        //creating director for the second company
        Director director2 = new Director("Vasil", 36);
        //creating the second company and setting its current rental price for the studio;
        MusicCompany company2 = new MusicCompany("The voice", director2);
        company2.setPrice(17);

        //creating the first client which rents the first company's studio;
        Client Samantha = new Client("Samantha");
        Samantha.rentCompany(company1, 3);
        Samantha.rentedCompany();

        //creating the second client which rents the first company's studio;
        Client John = new Client("John");
        John.rentCompany(company1, 6);
        John.rentedCompany();

        //checking the revenue of company1 in leva, euro & dollars; also reducing its current price by 10%;
        company1.checkEarnings();
        company1.checkEarningsEuroDollars();
        company1.percentageReduction(10);

        //creating the second client which rents the first company's studio;
        Client Peter = new Client("Peter");
        Peter.rentCompany(company1, 1);
        Peter.rentedCompany();

        //comparing the both companies by the price and age of directors;
        company1.compareCompanies(company2);
        company1.compareByDirectorAge(company2);

        //final print of earnings and clients that rented the studio;
        company1.printClients();
        company1.checkEarnings();

    }
}
