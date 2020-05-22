import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;

public class Receipt {
    private static int numberOfReceipts= 0;
    private int receiptNumber = 0;
    private Cashier cashier;
    private String dateAndTime = "09:00h (05.05.2020)";
    private static int date = 0;
    private double receiptRevenue = 0;
    private static double revenue = 0;
    //Map<Goods,Integer>

    public Receipt(Cashier cashier){
        this.cashier = cashier;
        date+=10;
        String c = dateAndTime.substring(3,5);
        dateAndTime = dateAndTime.replace(dateAndTime.substring(0,2), String.valueOf(Integer.parseInt(dateAndTime.substring(0,2))+date/60));
        dateAndTime = dateAndTime.replace(c, String.valueOf((Integer.parseInt(c)+date)%60));
        receiptNumber++;
        numberOfReceipts += receiptNumber;
    }

    public File createReceipt(Map<Goods,Integer> goods, double priceForAll) throws IOException {
        receiptRevenue = priceForAll;
        revenue += priceForAll;
        receiptRevenue = priceForAll;
        File receipt = new File(String.valueOf(numberOfReceipts)+".txt");
        FileWriter writer = new FileWriter(receipt);

        writer.write("NUMBER: ");
        writer.write(String.valueOf(numberOfReceipts));
        writer.write("\n");
        writer.write("CASHIER: ");
        writer.write(cashier.getName());
        writer.write("\n");
        writer.write("DATE: ");
        writer.write(dateAndTime);
        writer.write("\n\n");
        writer.write("--------------------\n");
        for(Map.Entry<Goods, Integer> g : goods.entrySet()){
            writer.write(g.getKey().getName());
            writer.write("      ");
            writer.write(String.valueOf(g.getValue()));
            writer.write(" x ");
            writer.write(String.valueOf(g.getKey().getPrice()));
            writer.write("\n");
        }
        writer.write("        ____________\n");
        writer.write("        total: ");
        writer.write(String.valueOf(receiptRevenue));
        writer.close();
        return receipt;
    }

    public int getCount(){
        return numberOfReceipts;
    }

    public static double getRevenue(){
        return revenue;
    }

    public static int getNumberOfReceipts(){
        return numberOfReceipts;
    }
}
