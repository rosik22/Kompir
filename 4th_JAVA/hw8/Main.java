public class Main{
    public static void main(String[] args){
        Tailor Ivanka = new Tailor("Ivanka");
        Tailor Goshka = new Tailor("Goshka");

        Studio Armani = new Studio("Armani", 35);
        Armani.addTailor(Ivanka);
        Armani.addTailor(Goshka);

        
    }
}