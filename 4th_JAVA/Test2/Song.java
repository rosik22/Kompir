import java.io.Serializable;

public class Song implements Serializable {
    public static final long serialVersionUID = 1234L;
    private String name;
    private transient Category category;
    private double duration;

    public Song(String name, Category category, double duration) {
        this.name = name;
        this.category = category;
        this.duration = duration;
    }

    public String getCategory(){
        return category.name();
    }

    public String getName(){
        return name;
    }

    public void setName(String text){
        this.name += text;
    }

    @Override
    public String toString() {
        return "Project{" +
                "name='" + name + '\'' +
                ", category=" + category +
                ", duration=" + duration +
                '}';
    }
}
