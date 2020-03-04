package com.company;

public class Main {

    public static void main(String[] args) {
        int num = 6;
        int arr[] = new int[2 * num];

        int cnt = num * 2 - 1;
        for (int k = 0; k < num; k++) {
            arr[k] = k + 1;
            arr[cnt] = k + 1;
            cnt--;
        }

        cnt = num * 2 - 1;
        int h = num * 2;
        for (int i = 0; i < num; i++) {
            int j = i;
            while (j < h) {
                System.out.print(arr[j]);
                j++;
            }
            System.out.println();
            h--;
        }

        for (int l = 0; l <= num; l++) {
            int j = num - l;
            while (j < h) {
                System.out.print(arr[j]);
                j++;
            }
            System.out.println();
            h++;
        }
    }
}
