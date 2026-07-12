package cn.envir_0514_07._08;

//定义无参、无返回值的函数式接口
@FunctionalInterface
interface Animal {
    void shout();

}

class AnimalDemo {
    // 创建一个动物叫的方法，并传入接口对象Animal作为参数
    public void animalShout(Animal animal) {
        animal.shout();
    }
}

public class _08 {
    public static void main(String[] args) {
        AnimalDemo ad = new AnimalDemo();
        // 匿名内部类方式：
//        System.out.println("匿名内部类方式:");
        ad.animalShout(new Animal() {
            @Override
            public void shout() {
                System.out.println("匿名内部类方式:无参,无返回值的函数式接口调用");

            }
        });
        // Lambda表达式方式：
        ad.animalShout(() -> {
            System.out.println("Lambda表达式方式:无参,无返回值的函数式接口调用");
        });
        // Lambda表达式省略方式：
        ad.animalShout(() -> System.out.println("Lambda表达式方式:无参,无返回值的函数式接口调用"));

    }
}
