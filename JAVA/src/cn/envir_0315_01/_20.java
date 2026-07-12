package cn.envir_0315_01;
import java.util.Scanner;
public class _20 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入体重(kg)");
        float height = sc.nextFloat();

        System.out.println("请输入身高(m)");
        float high = sc.nextFloat();

        float bmi = height / (high * high);

        String health = "";
        if(bmi<18.5)
            health = "偏瘦";
        else if(bmi<=25)
            health = "正常";
        else if (bmi<=30)
            health = "超重";
        else if (bmi<=35)
            health = "轻度肥胖";
        else if(bmi<=40)
            health = "中度肥胖";
        else
            health = "重度肥胖";

        System.out.println("健康状况为"+health);
    }
}
