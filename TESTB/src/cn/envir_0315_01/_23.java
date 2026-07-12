package cn.envir_0315_01;
import java.util.Scanner;
public class _23 {
    public static void main(String[] args) {
        String userName = "wangwu";
        String passWord = "wang123";

        String putName = "",putPassWord = "";

        Scanner sc = new Scanner(System.in);

        System.out.println("请输入用户名:");
        putName = sc.next();
        System.out.println("请输入密码:");
        putPassWord = sc.next();

        boolean booluser = true,boolcaptcha = true,boolpass = true;

        int captcha=(int)(Math.random()*9000)+1000;
        System.out.println("请输入验证码:"+ captcha);
        int num = sc.nextInt();

        if(captcha!=num)
            boolcaptcha = false;
        if(!putName.equals(userName))
            booluser = false;
        if (!putPassWord.equals(passWord))
            boolpass = false;

        if(!booluser)
            System.out.println("用户不存在!");
        else if (!boolpass)
            System.out.println("密码错误");
        else if (!boolcaptcha)
            System.out.println("验证码错误");

        if(booluser&&boolpass&&boolcaptcha){
            System.out.println("登录成功");
        }



    }
}
