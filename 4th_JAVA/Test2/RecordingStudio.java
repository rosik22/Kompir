import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class RecordingStudio {
    private String name;
    private List<Singer> singers;

    public RecordingStudio(String name) {
        this.name = name;
        this.singers = new ArrayList<Singer>();
    }

    public void addSinger(Singer singer) {
        if (!singers.contains(singer)) {
            this.singers.add(singer);
        }
    }

    // Task 1
    public void writeTextInSong(Song song, String text) throws NotAppropriateCategoryException {
        if(song.getCategory().equals("ROCK")){
            song.setName(text);
            System.out.println("Changed name: " + song.getName());
        }
        else{ 
            throw new NotAppropriateCategoryException(song.getCategory());
        }
    }

    // Task 2
    public void saveSingersInFile(String filename) {
        try(FileWriter file = new FileWriter(filename);){
            for(Singer singer: singers){
                file.write(singer.getName());
                file.write("*");
            }
            file.close();
        }catch(IOException e){
            System.out.println(e);
        }
    }

    // Task 3
    public void serializeSong(Song song, String filename) {
        try (FileOutputStream fos = new FileOutputStream(filename); ObjectOutputStream outputStream = new ObjectOutputStream(fos);) {
            outputStream.writeObject(song);
        }catch(IOException e){
            System.out.println(e);
        }
    }

    // Task 3
    public Song deserializeSong(String filename) {
        try (FileInputStream fis = new FileInputStream(filename); ObjectInputStream inputStream = new ObjectInputStream(fis);){
            Song song = (Song) inputStream.readObject();
            return song;
        }catch (ClassNotFoundException ex) {
            System.err.println("Class not found: " + ex);
        }catch(IOException e){
            System.out.println(e);
        }
        return null;
    }

    // Task 4
    public boolean readSongName(Song song, String targetString) {
        String songName = song.getName();
        int size = songName.length()/2;
        if(songName.lastIndexOf(targetString) > size){
            return true;
        }
        return false;
    }

    // Task 5
    public void recordSongs(Singer singer) {
        singer.start();
    }

    @Override
    public String toString() {
        return "Ide{" +
                "name='" + name + '\'' +
                ", singers=" + singers +
                '}';
    }
}
