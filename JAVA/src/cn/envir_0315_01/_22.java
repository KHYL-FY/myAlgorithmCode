package cn.envir_0315_01;
import java.util.Scanner;
public class _22 {
    public static void main(String[] args) {

        int randomblue=(int)(Math.random()*16)+1;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入蓝球号码");
        int blue = sc.nextInt();

        //int [] red = {2,15,16,17,22,32};
        if(blue == randomblue){
            System.out.println("恭喜你中了六等奖,奖金两元");
        }
        else{
            System.out.println("再来一注吧");
        }
        System.out.println("本期号码为");
        System.out.println("红球: 2,15,16,17,22,32");
        System.out.print("蓝球: ");
        System.out.print(randomblue);
    }
}
