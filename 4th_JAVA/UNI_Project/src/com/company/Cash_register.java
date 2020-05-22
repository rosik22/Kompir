import java.io.File;
import java.io.IOException;
import java.util.Map;
import java.util.Scanner;

public class Cash_register{
    private Cashier cashierOnShift;
    
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
        double priceForAll = 0;
        for(Map.Entry<Goods, Integer> g : goods.entrySet()){
            priceForAll += g.getKey().getPrice()*g.getValue();
        }
        Receipt rec = new Receipt(cashierOnShift);
        File rec1 = rec.createReceipt(goods, priceForAll);
        System.out.println();

        //new method - try-catch
        Scanner input = new Scanner(rec1);
        while (input.hasNextLine()){
            System.out.println(input.nextLine());
        }
        input.close();
    }
}
