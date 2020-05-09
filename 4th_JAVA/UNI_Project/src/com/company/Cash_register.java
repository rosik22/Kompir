import java.io.IOException;
import java.util.Map;

public class Cash_register {
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
        System.out.println("Price all: " + priceForAll);
        Receipt rec = new Receipt(cashierOnShift);
        rec.createReceipt(goods, priceForAll);
    }
}
