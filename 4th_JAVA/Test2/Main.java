
public class Main {

    public static void main(String[] args) {
        RecordingStudio studio1 = new RecordingStudio("The voice");
        Singer Eminem = new Singer("Eminem");
        Singer Rihanna = new Singer("Rihanna");
        Song song1 = new Song("song1", Category.ROCK, 3.20);
        Song song2 = new Song("song2", Category.POP, 2.45);
        Song song3 = new Song("song3", Category.POP, 4.20);
        Song song4 = new Song("song4", Category.POP, 3.40);
        Eminem.addSong(song1);
        Eminem.addSong(song2);
        Rihanna.addSong(song3);
        Rihanna.addSong(song4);
        studio1.addSinger(Eminem);
        studio1.addSinger(Rihanna);


        //Task 1
        try{
            studio1.writeTextInSong(song1, "shalal");
        }catch(NotAppropriateCategoryException e){
            System.out.println(e);
        }

        //Task 2
        studio1.saveSingersInFile("singers.txt");

        //Task 3
        studio1.serializeSong(song1, "song.ser");
        Song song11 = studio1.deserializeSong("song.ser");
        System.out.println(song11);

        //Task 4
        System.out.println(studio1.readSongName(song1, "halal"));

        //Task 5
        studio1.recordSongs(Eminem);
        studio1.recordSongs(Rihanna);
    }
}