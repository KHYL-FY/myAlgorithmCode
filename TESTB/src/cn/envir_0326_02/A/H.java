package cn.envir_0326_02.A;

public class H {
    public static void main(String[] args) {
        int day = 5;
        int peach = 1;

        System.out.println("第" + day + "天早上，还剩 " + peach + " 个桃子");

        while (day > 1) {
            day--;
            peach = 2 * (peach + 1);
            System.out.println("第" + day + "天早上，还剩 " + peach + " 个桃子");
        }

        System.out.println("猴子第一天共摘了 " + peach + " 个桃子");
    }
}
