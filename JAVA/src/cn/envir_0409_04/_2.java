package cn.envir_0409_04;

class Rectangle {
    private int height;
    private int width;

    Rectangle() {
    }

    Rectangle(int width, int height) {
        this.height = height;
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    @Override
    public String toString() {
        return "Rectangle[" +
                "height=" + height +
                ", width=" + width +
                ']';
    }

    public int zhouchang() {
        return height * 2 + width * 2;
    }

    public int area() {
        return height * width;
    }
}

public class _2 {
    public static void main(String[] args) {
        Rectangle a = new Rectangle(10, 8);
        System.out.println(a.toString());

        System.out.println("周长为" + a.zhouchang());
        System.out.println("面积为" + a.area());

        Rectangle b = new Rectangle(12, 9);
        System.out.println(b.toString());

        System.out.println("周长为" + b.zhouchang());
        System.out.println("面积为" + b.area());

    }
}
