package cn.envir_0423_05;

class rectangle {
    private double x;
    private double y;

    rectangle() {

    }

    rectangle(double x, double y) {
        setX(x);
        setY(y);
    }

    public double area() {
        return x * y;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return "长方形长为" + x
                + "宽为" + y
                + "面积为" + area();
    }
}

class circle extends rectangle {
    public static double pi = 3.1415926;

    circle() {

    }

    circle(int x) {
        setX(x);
    }

    @Override
    public double area() {
        return pi * getX() * getX();
    }

    @Override
    public String toString() {
        return "圆的半径为" + getX() + "  "
                + "面积为" + area();
    }
}

class sphere extends rectangle {
    sphere() {
    }

    sphere(double x) {
        setX(x);
    }

    @Override
    public double area() {
        return getX() * getX() * getX();
    }

    @Override
    public String toString() {
        return "球的半径为" + getX() + "  "
                + "表面积为" + area();
    }
}

class cylinder extends rectangle {
    public static double pi = 3.1415926;

    cylinder() {
    }

    cylinder(double x, double y) {
        super(x, y);
    }

    @Override
    public double area() {
        return getX() * getX() * pi * 2 + getX() * 2 * pi * getY();
    }

    @Override
    public String toString() {
        return "圆柱体的底面半径为" + getX() + "  "
                + "高为" + getX() + "  "
                + "表面积为" + area();
    }
}

public class _4 {
    public static void main(String[] args) {
        rectangle a = new rectangle(2.4, 5.6);
        System.out.println(a.toString());

        circle b = new circle(3);
        System.out.println(b.toString());

        sphere c = new sphere(3);
        System.out.println(c.toString());

        cylinder d = new cylinder(3, 5);
        System.out.println(d.toString());
    }
}
