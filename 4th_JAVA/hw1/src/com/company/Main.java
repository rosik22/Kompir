package com.company;

public class Main {

    public  static void check_number(int bottom, int top, int difference){
        String convertInt;
        String finalString;
        for(int i = bottom; i <= top; i++){
            convertInt = Integer.toString(i);
            char first = convertInt.charAt(0);
            String middle = convertInt.substring(1, convertInt.length());
            finalString = middle + first;
            int finalInt = Integer.parseInt(finalString);
            int abs = Math.abs(i-finalInt);
            if(abs > difference) System.out.println(i +" "+ finalInt+" => "+ i +"-"+finalInt+" = "+abs+" > "+difference);
        }
    }

    public static void main(String[] args) {
        check_number(10, 10_000, 5_000);
    }
}
