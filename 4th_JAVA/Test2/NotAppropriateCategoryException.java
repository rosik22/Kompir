public class NotAppropriateCategoryException extends Exception{
    private final String category;
    public NotAppropriateCategoryException(String category){
        this.category = category;
    }

    @Override
    public String toString(){
        return "NotAppropriateCategoryException{ category: " + category + " }";
    }
}