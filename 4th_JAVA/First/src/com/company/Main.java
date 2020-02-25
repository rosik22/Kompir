package com.company;

public class Main {
    //task 1
    public static void quadraticEquation(double a, double b, double c){
        double d = b * b - 4 * a * c;
        if (d == 0){
            double root = -b/(2 * a);
            System.out.println("root is: " + root);
        }
        else if (d > 0){
            double root1 = (-b + Math.sqrt(d)) / (2 * a);
            double root2 = (-b - Math.sqrt(d)) / (2 * a);
            System.out.println("root1: " + root1);
            System.out.println("root2: " + root2);
        }
        else {
            System.out.println("No real roots");
        }
    }

    //task 3
    public  static double average(int bottom, int top){
        bottom = 5 - bottom%5;
        double count = 0;
        double ans = 0;
        while (bottom < top){
            if(bottom % 3 != 0){
                ans += bottom;
            }
            count++;
            bottom += 5;
        }
        if(count > 0) return ans/count;
        else {
            System.out.println("No such number");
            return 0;
        }
    }

    //task 6
    public static int sumOfDivisors(int num){
        int sum=0;
        for(int i=1; i<= num/2; i++){
            if(num%i == 0) sum+= i;
        }
        return sum;
    }

    public static boolean isPerfect(int number){
        return sumOfDivisors(number) == number;
    }

    //task 7
    public static void displayPerfectNumbers(int bottom, int top){
        if(bottom > top) System.out.println("Not valid");
        for(int i=bottom; i<=top; i++){
            if(isPerfect(i)){
                System.out.println(i + " ");
            }
        }
    }

    //task 8
    public static boolean isPrime(int num){
        for(int i = 2; i<= Math.sqrt(num); i++){
            if(num%i == 0) return false;
        }
        return true;
    }

    //task 9
    public static void displayPrimeNumbers(int bottom, int top){
        if (bottom > top) System.out.println("Not valid");
        for(int i = bottom; i <= top; i++){
            if (isPrime(i)){
                System.out.println(i + " ");
            }
        }
    }
    //task 10

    public static void main(String[] args){
        quadraticEquation(3, 5 , 7);
        double av_ans = average(3, 40);
        boolean perf_ans = isPerfect(28);
        displayPerfectNumbers(3, 40);
        boolean pri_ans = isPrime(11);
        displayPrimeNumbers(3, 40);
    }

}





