package cn.envir_0315_01;
import java.util.Scanner;

public class _14 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int ge=0,shi=0,bai=0;

        ge = num % 10;
        shi = num /10 %10;
        bai = num/100;

        System.out.println(""+ge+shi+bai);
    }
}
