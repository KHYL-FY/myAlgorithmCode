package cn.javaWork;

import java.util.Random;
import java.util.Scanner;
public class LoginAndRegister {

        static boolean isRegistered = false;
        static boolean isLoggedIn = false;
        static String regUsername = "";
        static String regPassword = "";
        static int cardNumber = 0;

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            while (true) {
                showMenu();
                int choice = sc.nextInt();
                switch (choice) {
                    case 1:
                        register(sc);
                        break;
                    case 2:
                        login(sc);
                        break;
                    case 3:
                        if (isLoggedIn) {
                            lottery(sc);
                        } else {
                            System.out.println("请先登录！");
                        }
                        break;
                    case 4:
                        System.out.println("感谢使用，再见！");
                        sc.close();
                        return;
                    default:
                        System.out.println("您的输入有误！");
                }
            }
        }

        public static void showMenu() {
            System.out.println("===== 幸运抽奖系统 =====");
            System.out.println("1. 注册");
            System.out.println("2. 登录");
            System.out.println("3. 幸运抽奖");
            System.out.println("4. 退出");
            System.out.print("请选择：");
        }

        public static void register(Scanner sc) {
            if (isRegistered) {
                System.out.println("您已经注册过了，请直接登录！");
                return;
            }
            System.out.print("请输入用户名：");
            regUsername = sc.next();
            System.out.print("请输入密码：");
            regPassword = sc.next();
            Random rand = new Random();
            cardNumber = rand.nextInt(9000) + 1000;
            isRegistered = true;
            System.out.println("注册成功！");
            System.out.println("用户名：" + regUsername);
            System.out.println("密码：" + regPassword);
            System.out.println("卡号：" + cardNumber);
        }

        public static void login(Scanner sc) {
            if (!isRegistered) {
                System.out.println("请先注册！");
                return;
            }
            if (isLoggedIn) {
                System.out.println("您已经登录了！");
                return;
            }
            for (int i = 1; i <= 3; i++) {
                System.out.print("请输入用户名：");
                String name = sc.next();
                System.out.print("请输入密码：");
                String pwd = sc.next();
                if (name.equals(regUsername) && pwd.equals(regPassword)) {
                    isLoggedIn = true;
                    System.out.println("欢迎您，" + regUsername + "！登录成功！");
                    return;
                } else {
                    if (i < 3) {
                        System.out.println("用户名或密码错误，您还有" + (3 - i) + "次机会");
                    } else {
                        System.out.println("三次机会已用完，登录失败！");
                    }
                }
            }
        }

        public static void lottery(Scanner sc) {
            System.out.print("请输入您的卡号：");
            int inputCard = sc.nextInt();
            if (inputCard != cardNumber) {
                System.out.println("卡号错误！");
                return;
            }
            Random rand = new Random();
            int[] luckyNumbers = new int[5];
            System.out.print("今日的幸运数字为：");
            for (int i = 0; i < luckyNumbers.length; i++) {
                luckyNumbers[i] = rand.nextInt(9000) + 1000;
                System.out.print(luckyNumbers[i] + " ");
            }
            System.out.println();
            boolean isLucky = false;
            for (int i = 0; i < luckyNumbers.length; i++) {
                if (luckyNumbers[i] == cardNumber) {
                    isLucky = true;
                    break;
                }
            }
            if (isLucky) {
                System.out.println("恭喜您，您是今日的幸运会员！");
            } else {
                System.out.println("很遗憾，您不是今日的幸运会员！");
            }
        }
    }

