package com.company;

public class Novel extends Book{
    private String novelAbstract;

    public Novel(double size, String formatType, String title, Author author, String ISBN, String novelAbstract){
        super(size,formatType,title,author,ISBN);
        this.novelAbstract = novelAbstract;
    }

    public String getNovelAbstract(){ return novelAbstract;}

    @Override
    public String toString(){
        return super.toString() + " Novel{ " + "novelAbstract " + novelAbstract + "}";
    }
}
