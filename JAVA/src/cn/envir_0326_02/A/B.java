package cn.envir_0326_02.A;

import java.util.Scanner;
public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入一个整数:");

        int n = scanner.nextInt();

        boolean prime = true;
        for(int i = 2; i <= (int)Math.sqrt(n); i++){
            if(n % i == 0){
                prime = false;
                break;
            }
        }

        if(prime){
            System.out.println(n + "是一个素数");
        }
        else System.out.println(n + "不是一个素数");

    }
}
