package cn.envir_0326_02.A;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int ans = (int)(Math.random()*100) + 1;

        int n = sc.nextInt();
        while(true){
            if(n > ans){
                System.out.println("猜大了");
            }
            if (n < ans) {
                System.out.println("猜小了");
            }
            if(n == ans){
                System.out.println("你猜对了");
                break;
            }
            n = sc.nextInt();
        }
    }
}
