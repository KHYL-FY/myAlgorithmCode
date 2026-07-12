package cn.envir_0409_04;

class phone {
    private int price;
    private String brand;
    private String color;

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String toString() {
        return "Phone[" +
                "brand='" + brand + '\'' +
                ", price=" + price +
                ", color='" + color + '\'' +
                ']';
    }
//
//    @Override
//    public String toString() {
//        return super.toString();
//    }
}

public class _1 {
    public static void main(String[] args) {
        phone p = new phone();

        System.out.println(p.getBrand());
        System.out.println(p.getPrice());
        System.out.println(p.getColor());

        p.setBrand("华为");
        p.setPrice(3888);
        p.setColor("土豪金");

        System.out.println(p.toString());
    }


}
