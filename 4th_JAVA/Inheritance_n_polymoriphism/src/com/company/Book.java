package com.company;

public class Book extends Document{
    private final Author author;
    private final String ISBN;

    public Book(double size, String formatType, String title, Author author, String ISBN){
        super(size,formatType,title);
        this.author = author;
        this.ISBN = ISBN;
    }

    public Author getAuthor(){ return author;}

    public String getISBN() { return ISBN;}

    @Override
    public String toString(){
        return super.toString() + " Book{" + " author " + author +  ", ISBN " + ISBN + "}" ;
    }
}
