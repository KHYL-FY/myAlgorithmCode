package cn.envir_0423_05;

class animal {
    public void eat() {

    }

    public void sleep() {
        System.out.println("睡觉");
    }
}

class rabbit extends animal {

    public void eat() {
        System.out.println("兔子吃草");
    }

}

class tiger extends animal {
    @Override
    public void eat() {
        super.eat();
        System.out.println("老虎吃肉");
    }
}

public class _3 {
    public static void main(String[] args) {
        rabbit a = new rabbit();
        a.eat();
        a.sleep();
        tiger b = new tiger();
        b.eat();
        b.sleep();
    }
}
