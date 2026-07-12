package cn.envir_0514_07._01;

class Outer {
    int num = 10;

    class Inner {
        int num2 = 20;

        public void show() {
            System.out.println(num);
        }
    }
}

public class _1 {
    public static void main(String[] args) {
        Outer.Inner a = new Outer().new Inner();
        System.out.println(a.num2);
        a.show();

    }
}