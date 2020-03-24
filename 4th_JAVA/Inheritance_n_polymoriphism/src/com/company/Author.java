package com.company;

public class Author {
    private String authorName;

    public Author(String authorName){
        this.authorName = authorName;
    }

    public String getName(){ return authorName;}

    public String toString(){
        return " Author{" + " author " + authorName + "}" ;
    }
}
