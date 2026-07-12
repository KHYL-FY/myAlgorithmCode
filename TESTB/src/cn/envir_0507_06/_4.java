package cn.envir_0507_06;

interface Shape {
    double area(double a);
}

class Square implements Shape {
    @Override
    public double area(double a) {
        return a * a;
    }
}

class Circle implements Shape {
    public static double pi = 3.1415926;

    @Override
    public double area(double a) {
        return pi * a * a;
    }
}

class ShapeDemo {
    public Square a = new Square();
    public Circle b = new Circle();

    public void test() {
        System.out.println(a.area(3));
        System.out.println(b.area(3));
    }

}

public class _4 {
    public static void main(String[] args) {
        ShapeDemo a = new ShapeDemo();

        a.test();
    }
}
