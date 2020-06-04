public class Tailor implements Runnable {
    private String name;
    private Studio studio;
    private Thread t;
    private int currCloth = 0;

    public Tailor(String name) {
        this.name = name;
    }

    public void addStudio(Studio studio) {
        this.studio = studio;
    }

    public String getName() {
        return name;
    }
    
    public void start() {
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        while (studio.getNumberOfClothesNeeded() > 0) {
            studio.getCloth();
            currCloth++;
            System.out.println(Thread.currentThread().getName() + " is sewing cloth number: " + currCloth);
        }
        System.out.println(Thread.currentThread().getName() + " finished and has sewn " + currCloth + " clothes.");
    }
}