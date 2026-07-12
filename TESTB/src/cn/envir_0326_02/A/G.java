package cn.envir_0326_02.A;

import java.util.Scanner;
public class G {
    public static int gcd(int num1,int num2){
        if (num2 == 0){
            return num1;
        }

        return gcd(num2, num1%num2);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入第一个整数:");
        int num1 = sc.nextInt();
        System.out.println("请输入第二个整数:");
        int num2 = sc.nextInt();

        int gcd_num = gcd(num1,num2);

        System.out.println("最大公约数为" + gcd_num);
        System.out.println("最小公倍数为" + num1*num2/gcd_num);

    }
}
