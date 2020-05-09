package com.company;

import com.company.finance.*;
import com.company.hotel.Hotel;
import com.company.hotel.InsufficientNumberOfRoomsException;
import com.company.hotel.RoomIsRentedException;

import java.util.Currency;

public class Main {

    public static void main(String[] args) {
        //Box
	    Box box = new Box(2,3,4);
	    System.out.println(box);
	    double increasePercentage = 300;
	    try{
	        box.increaseDimensions(increasePercentage);
        }catch (IllegalArgumentException e){
	        e.printStackTrace();
        }
	    System.out.println(box);
	    double volumeNumber = 100;
	    box.optionalIncreaseDimensions(increasePercentage, volumeNumber);

	    //Rent Hotel Rooms
        Hotel hotel = new Hotel(5);
        try{
            hotel.rentRoom(2);
            hotel.rentRoom(1);
            hotel.rentRoom(2);
            hotel.rentRoom(4);
            hotel.rentRoom(6);
        }catch (RoomIsRentedException | InsufficientNumberOfRoomsException e){
            e.printStackTrace();
        }

        //Bank Accounts
        Bank unicreditBulbank = new Bank("UnicreditBulbank", 800, 5000);
        Customer maria = new Customer("Maria");
        Account mariasAccount = new Account(maria, "UC823SC2323");
        unicreditBulbank.addAccount(mariasAccount);
        unicreditBulbank.deposit(mariasAccount,1000);
        unicreditBulbank.displayAccount();

        try{
            unicreditBulbank.withdrawATM(mariasAccount,500);
            unicreditBulbank.withdrawATM(mariasAccount, 600);
            unicreditBulbank.withdrawCashDesk(mariasAccount,6000);
        }catch (LimitExceededException e){
            e.printStackTrace();
        }catch (NotEnoughFundsException e){
            e.printStackTrace();
        }
    }
}
