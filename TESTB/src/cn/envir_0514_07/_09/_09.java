package cn.envir_0514_07._09;

//定义有参、有返回值的函数式接口
@FunctionalInterface
interface Calculate {
    int sum(int a, int b);
}

class CalculateDemo {
    // 创建一个求和的方法，并传入两个int类型以及接口Calculate类型的参数
    public void add(int num1, int num2, Calculate calculate) {
        int result = calculate.sum(num1, num2);
        System.out.println(num1 + "+" + num2 + "的和为：" + result);
    }
}

public class _09 {
    public static void main(String[] args) {
        CalculateDemo cd = new CalculateDemo();

        // 匿名内部类方式
        cd.add(10, 20, new Calculate() {
            @Override
            public int sum(int a, int b) {
                return a + b;
            }
        });

        // Lambda表达式方式:
        cd.add(10, 20, (int a, int b) -> {
            return a + b;
        });

        // Lambda表达式省略方式:
        cd.add(10, 20, (int a, int b) -> a + b);

    }
}
