import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Receipt {
    private static int numberOfReceipts= 0;
    private int receiptNumber = 0;
    private Cashier cashier;
    private String DateAndTime;
    private LocalDateTime time = LocalDateTime.now();
    private DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss dd/MM/yyyy");
    private double receiptRevenue = 0;
    Map<Goods,Integer> listOfGoods = new HashMap<Goods, Integer>();


    public Receipt(Cashier cashier){
        this.cashier = cashier;
        DateAndTime = formatter.format(time);
        receiptNumber++;
        numberOfReceipts += receiptNumber;
    }

    public File createReceipt(Map<Goods,Integer> goods, double priceForAll) throws IOException {
        listOfGoods = goods;
        receiptRevenue = priceForAll;
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
        writer.write(DateAndTime);
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
        writer.write(String.format("%.2f", receiptRevenue));
        writer.close();
        displayReceipt(receipt);
        return receipt;
    }

    private void displayReceipt(File receipt) {
        try {
            Scanner output = new Scanner(receipt);
            while (output.hasNextLine()) {
                System.out.println(output.nextLine());
            }
            output.close();
        } catch (Exception e) {
            System.out.println("Something went wrong with reading the file");
        }
    }

    public int getCount(){
        return numberOfReceipts;
    }

    public static int getNumberOfReceipts(){
        return numberOfReceipts;
    }
}
