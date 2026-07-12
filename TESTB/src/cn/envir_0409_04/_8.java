package cn.envir_0409_04;

class Car {
    private String brand;
    private double price;
    private String color;

    public Car() {
        this("未知品牌", 0.0, "未知颜色");
    }

    public Car(String brand, double price, String color) {
        this.brand = brand;
        this.price = price;
        this.color = color;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Car{" +
                "brand='" + brand + '\'' +
                ", price=" + price +
                ", color='" + color + '\'' +
                '}';
    }
}

public class _8 {
    public static void main(String[] args) {
        Car car1 = new Car();
        car1.setBrand("奥迪");
        car1.setPrice(388888);
        car1.setColor("黑色");
        System.out.println(car1);

        Car car2 = new Car("特斯拉", 289900, "红色");
        System.out.println(car2);
    }
}
