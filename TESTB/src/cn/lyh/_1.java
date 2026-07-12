package cn.lyh;

interface Shape {
    double area(double x);
}

class Square implements Shape {
    @Override
    public double area(double side) {
        return side * side;
    }
}

class Circle implements Shape {
    @Override
    public double area(double r) {
        return r * r * Math.PI;
    }
}

public class _1 {
    public static void main(String[] args) {
        Square s = new Square();
        Circle c = new Circle();

        System.out.println(s.area(3));
        System.out.println("------------------");
        System.out.println(c.area(3));
    }
}
