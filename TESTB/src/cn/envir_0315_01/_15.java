package cn.envir_0315_01;
import java.util.Scanner;

public class _15 {
    public static void main(String[] args) {
        System.out.println("输入一个小数:");
        double num = 0;

        Scanner sc = new Scanner(System.in);

        num = sc.nextDouble();

        int round_ = (int) (num+0.5);

        System.out.println("四舍五入后为:"+round_);

        int n = sc.nextInt();//整数
        System.out.println(n);

        String str1 = sc.next();
        System.out.println(str1);//不带空格的字符串

        sc.nextLine();
        String str2 = sc.nextLine();//带空格的字符串
        System.out.println(str2);
    }
}
