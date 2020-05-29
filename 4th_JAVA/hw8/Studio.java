import java.util.ArrayList;

public class Studio{
    private String name;
    private int originalNumber;
    private int numberOfClothesNeeded;
    private ArrayList<Tailor> listOfTailors;

    public Studio(String name, int numberOfClothesNeeded){
        this.name = name;
        this.numberOfClothesNeeded = numberOfClothesNeeded;
        originalNumber = numberOfClothesNeeded;
        listOfTailors = new ArrayList<Tailor>();
    }

    public String getName(){
        return name;
    }

    public int getNumberOfClothesNeeded(){
        return numberOfClothesNeeded;
    }

    public void addTailor(Tailor tailor){
        listOfTailors.add(tailor);
    }

    public void Sewing(){
        if(numberOfClothesNeeded > 0){
            numberOfClothesNeeded--;
        }
        System.out.println(Thread.currentThread().getName() 
                            + " is sewing cloth number " +
                            (originalNumber-numberOfClothesNeeded));
    }
}