import java.io.File;
import java.io.IOException;
import java.util.Map;
import java.util.Scanner;

public class Cash_register{
    private Cashier cashierOnShift;
    private double totalFromThePurchase;
    private File receipt;
    
    Cash_register(Cashier cashierOnShift){
        this.cashierOnShift = cashierOnShift;
    }

    public void setCashierOnShift(Cashier cashierOnShift){
        this.cashierOnShift = cashierOnShift;
    }

    public Cashier getCashierOnShift(){
        return cashierOnShift;
    }

    public void payForGoods(Map<Goods,Integer> goods) throws IOException {
        totalFromThePurchase = 0;
        for(Map.Entry<Goods, Integer> g : goods.entrySet()){
            totalFromThePurchase += g.getKey().getPrice()*g.getValue();
        }
        Receipt rec = new Receipt(cashierOnShift);
        this.receipt = rec.createReceipt(goods, totalFromThePurchase);
        System.out.println();

        displayReceipt(receipt);
    }

    private void displayReceipt(File receipt){
        try{
            Scanner output = new Scanner(receipt);
            while (output.hasNextLine()){
                System.out.println(output.nextLine());
            }
            output.close();
        }catch (Exception e){
            System.out.println("Something went wrong with reading the file");
        }
    }

    public File getReceipt(){
        return receipt;
    }

    public double getTotalFromThePurchase(){
        return totalFromThePurchase;
    }
}
