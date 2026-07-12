package cn.envir_0514_07._03;

class Outer {
    static int num2 = 20;
    int num = 10;

    static class Inner {
        static int num3 = 30;
        int num4 = 40;

        public void show() {
            System.out.println(num2);
            System.out.println(num3);
            System.out.println(num4);
        }
    }
}

public class _03 {
    public static void main(String[] args) {
        Outer.Inner a = new Outer.Inner();

        a.show();
    }
}
