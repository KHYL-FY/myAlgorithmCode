package cn.envir_0514_07._04;

class Outer {
    int num = 10;

    public void method() {
        int num2 = 20;
        class Inner {  //局部内部类
            public void show() {
                System.out.println(num);
                System.out.println(num2);
            }
        }

        Inner a = new Inner();

        a.show();
    }
}

public class _04 {
    public static void main(String[] args) {
        Outer outer = new Outer();
        outer.method();

    }
}
