package cn.envir_0507_06;

interface SayHello {
    void printMessage();
}

class ChineseSayHello implements SayHello {
    @Override
    public void printMessage() {
        System.out.println("你好,今天吃饭了吗");
    }
}

class EnglishSayHello implements SayHello {
    @Override
    public void printMessage() {
        System.out.println("hello, 今天天气好nice啊");
    }
}

class SayHelloDemo {
    public ChineseSayHello a = new ChineseSayHello();
    public EnglishSayHello b = new EnglishSayHello();

    public void test() {
        a.printMessage();
        b.printMessage();
    }
}

public class _3 {
    public static void main(String[] args) {
        SayHelloDemo a = new SayHelloDemo();

        a.test();
    }
}
