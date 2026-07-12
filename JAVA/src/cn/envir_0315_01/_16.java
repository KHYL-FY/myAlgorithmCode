package cn.envir_0315_01;
//鸡兔同笼
import java.util.Scanner;
public class _16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("输入头的总数");
        int heads = sc.nextInt();

        System.out.println("输入脚的总数");
        int foots = sc.nextInt();

        int rabbit = (4*heads - foots) / 2;
        int chicken =heads - rabbit;

        System.out.println("兔子的个数为 "+rabbit);
        System.out.println("鸡的个数为 "+chicken);
    }
}
