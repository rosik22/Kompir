import java.util.ArrayList;
import java.util.List;

public class Singer implements Runnable{
    private String name;
    private List<Song> songs;

    public Singer(String name) {
        this.name = name;
        this.songs = new ArrayList<Song>();
    }

    public void addSong(Song song) {
        this.songs.add(song);
    }

    public String getName(){
        return name;
    }

    public void recordSongs() {
        for (Song song : songs) {
            System.out.println("Recording ... " + song);
        }
    }

    @Override
    public void run(){
        System.out.println(Thread.currentThread().getName() + " is recording");
        try{
            recordSongs();
            Thread.sleep(1000);
        }catch (InterruptedException e){
            System.out.println("The thread has been interupted");
        }
        System.out.println(Thread.currentThread().getName() + " stopped recording");
    }

    public void start(){
        Thread t = new Thread(this);
        t.start();
    }

    @Override
    public String toString() {
        return "Creator{" +
                "name='" + name + '\'' +
                '}';
    }
}
