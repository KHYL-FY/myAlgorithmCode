package cn.envir_0315_01;
import  java.util.Scanner;

public class _17 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("输入要查询的年份");
        int year = sc.nextInt();

        if((year % 4 == 0 && year % 100 != 0)||(year % 4 == 0 && year % 100 == 0)){
            System.out.println(year+"是闰年");
            System.exit(0);
        }
        else{
            System.out.println(year + "不是闰年");
        }
    }
}
