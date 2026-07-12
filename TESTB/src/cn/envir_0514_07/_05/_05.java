package cn.envir_0514_07._05;

abstract class Father {
    int num;

    public Father(int num) {
        this.num = num;
    }

    public abstract void method();

}

class Niming {

    public void show() {
        Father a = new Father(6) {
            @Override
            public void method() {
                System.out.println("num=" + num);
            }
        };
        
        a.method();
    }
}

public class _05 {
    public static void main(String[] args) {
        Niming niming = new Niming();
        niming.show();
    }
}
