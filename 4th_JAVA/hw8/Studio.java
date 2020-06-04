import java.util.ArrayList;

public class Studio{
    private String name;
    private int numberOfClothesToSew;
    private ArrayList<Tailor> listOfTailors;

    public Studio(String name, int numberOfClothesToSew){
        this.name = name;
        this.numberOfClothesToSew = numberOfClothesToSew;
        listOfTailors = new ArrayList<Tailor>();
    }

    public String getName(){
        return name;
    }

    public int getNumberOfClothesNeeded(){
        return numberOfClothesToSew;
    }

    public void addTailor(Tailor tailor){
        listOfTailors.add(tailor);
        tailor.addStudio(this);
    }

    synchronized public void getCloth(){
        numberOfClothesToSew--;
    }

    public void Sewing(){
        for(int i=0; i<listOfTailors.size(); i++){
            listOfTailors.get(i).start();
        }
    }
}