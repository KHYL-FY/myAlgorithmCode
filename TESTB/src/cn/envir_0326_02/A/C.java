package cn.envir_0326_02.A;

import java.util.Scanner;
public class C {
    public static void main(String[] args) {
        double high = 0.01;
        int n = 0;

        //Scanner sc = new Scanner(System.in);

        while(high < 8848.0){
            high *= 2;
            n++;
            System.out.println("折叠第"+n+"次的高度为"+high+"m");
        }

        System.out.println("要折叠"+n+"次");
    }
}
