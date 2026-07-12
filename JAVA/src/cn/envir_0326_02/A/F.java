package cn.envir_0326_02.A;

public class F {
    public static void main(String[] args) {
        double balance = 0;
        int day = 0;

        while (balance < 100) {
            day++;
            balance += 2.5;
            if (day % 5 == 0) {
                balance -= 6;
            }
            System.out.println("第"+day+"天的存款为"+balance+"元");
        }

        System.out.println("经过"+day+"小芳可以存100元");
    }
}
