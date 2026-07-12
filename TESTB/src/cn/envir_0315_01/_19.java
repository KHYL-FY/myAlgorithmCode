package cn.envir_0315_01;
import  java.util.Scanner;
public class _19 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入成绩");
        int score = sc.nextInt();

        score /= 10;

        switch (score){
            case 5:
                System.out.println("你的评级为不及格");
                break;
            case 6:
                System.out.println("你的评级为及格");
                break;
            case 7:
                System.out.println("你的评级为一般");
                break;
            case 8:
                System.out.println("你的评级为良好");
                break;
            case 10:
            case 9:
                System.out.println("你的评级为优秀");
                break;
            default:
                System.out.println("你的评级为不及格");
        }


    }
}
