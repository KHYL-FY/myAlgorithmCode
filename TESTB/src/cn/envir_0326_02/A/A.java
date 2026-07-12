package cn.envir_0326_02.A;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num = 8;
        while(n-->0){
            sum += num;
            num *= 10;
            num += 8;
        }

        System.out.println("sum=" + sum);
    }

}
