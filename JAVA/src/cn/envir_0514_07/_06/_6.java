package cn.envir_0514_07._06;

interface InterFace1 {
    int num = 100;

    void method();
}

class Niming2 {
    public void show() {
        InterFace1 a = new InterFace1() {
            @Override
            public void method() {
                System.out.println("num=" + num);
            }
        };

        a.method();
    }
}

public class _6 {
    public static void main(String[] args) {
        Niming2 a = new Niming2();
        a.show();
    }
}
