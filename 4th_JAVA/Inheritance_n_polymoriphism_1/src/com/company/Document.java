package com.company;

public class Document {
    private double size;
    private String formatType;
    private String title;

    public Document(){

    }

    public Document(double size, String formatType, String title){
        this.size = size;
        this.formatType = formatType;
        this.title = title;
    }

    public double getSize(){ return size;}

    public String getFormatType() { return formatType;}

    public String getTitle() {return title;}

    public String toString(){
        return "Document{ " + "size " + size + ", format type " + formatType + ", title " + title + "}" ;
    }
}
