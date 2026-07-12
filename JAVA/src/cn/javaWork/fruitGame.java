package cn.javaWork;
import java.util.Random;
import java.util.Scanner;
public class fruitGame {
    public static void main(String[] args) {
        String [] fruit = {" ","苹果","木瓜","西瓜","香蕉","橙子","葡萄"};
        int [] rewards = {2,5,10,20,50,100};
        System.out.println("游戏规则：");
        System.out.println("1. 初始赠送10个金币");
        System.out.println("2. 选择一种水果进行押注");
        System.out.println("3. 输入押注金额");
        System.out.println("4. 机器随机运转，若停在您选的水果上则获奖");
        System.out.println("5. 奖励 = 押注金币 × 奖励系数");
        System.out.println("6. 1号--苹果--2 2号--木瓜--5 3号--西瓜--10 4号--香蕉--20 5号--橙子--50 6号--葡萄--100");

        int coins = 10;
        System.out.println("您的初始金币为: "+ coins);

        int user_choice = -1;
        Scanner sc = new Scanner(System.in);
        int bet = 0;
        while(coins > 0){

            System.out.println("请输入要下注水果的对应编号");
            user_choice = sc.nextInt();
            if(!(user_choice >= 1 && user_choice <= 6)) {
                System.out.println("输入非法,请重新输入");
                continue;
            }
            System.out.println("您的当前金币为: "+coins);
            System.out.println("请输入你要下注的金币数:");
            while(true){
                bet = sc.nextInt();
                if(!(bet>0)){
                    System.out.println("请输入正确的金币数!");
                    continue;
                }
                if(bet>coins){
                    System.out.println("您的金币数不足,请重新输入");
                    continue;
                }
                break;
            }

            coins -= bet;

            Random ran = new Random();
            int result = ran.nextInt(6)+1;

            System.out.println("结果停在了:" + fruit[result]);
            if(user_choice == result){
                System.out.println("恭喜您中奖了");
                coins += (rewards[result]*bet);
                System.out.println("您当前的金币为 "+coins);
            }
            else{
                System.out.println("很遗憾您未中奖");
            }
            if(coins<=0) break;
            System.out.println("是否继续?");
            System.out.println("1.是");
            System.out.println("2.否");
            int again = 0;
            while(true){
                again = sc.nextInt();
                if(again!=1&&again!=2){
                    System.out.println("输入非法!,请重新输入");
                    continue;
                }
                else {
                    break;
                }
            }
            if(again == 1){
                System.out.println("游戏继续");
                continue;
            }
            else{
                break;
            }
        }

        System.out.println("游戏结束");


    }
}
