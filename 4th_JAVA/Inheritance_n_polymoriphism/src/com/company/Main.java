package com.company;

public class Main {
    public static void main(String[] args) {
	    Document document = new Document(10,".pdf","document");
	    Author author = new Author("Ivan Vazov");
	    Book book = new Book(11,".txt","Under the Yoke",author,"1312242421");
	    book.toString();
    }
}
