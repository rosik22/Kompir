public class Main{
    public static void main(String[] args){
        Tailor Ivanka = new Tailor("Ivanka");
        Tailor Goshka = new Tailor("Goshka");
        Tailor Petranka = new Tailor("Petranka");

        Studio Armani = new Studio("Armani", 10);
        Armani.addTailor(Ivanka);
        Armani.addTailor(Goshka);
        Armani.addTailor(Petranka);

        Armani.Sewing();
    }
}