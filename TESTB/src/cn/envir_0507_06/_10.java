package cn.envir_0507_06;

// 实验10 打印机多态
abstract class Printer {
    public abstract void print();
}

class BlackPrinter extends Printer {
    @Override
    public void print() {
        System.out.println("打印黑白纸张");
    }
}

class ColorPrinter extends Printer {
    @Override
    public void print() {
        System.out.println("打印彩色纸张");
    }
}


public class _10 {
    public static void main(String[] args) {
        Printer p = new BlackPrinter();
        p.print();

        p = new ColorPrinter();
        p.print();
    }
}
