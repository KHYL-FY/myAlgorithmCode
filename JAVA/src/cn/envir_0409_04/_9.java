package cn.envir_0409_04;

class Goods {
    String name;

    Goods(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

class Market {
    public String name;
    private Goods[] goodsList;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Goods[] getGoodsList() {
        return goodsList;
    }

    public void setGoodsList(Goods[] goodsList) {
        this.goodsList = goodsList;
    }

    public String sell(String name) {
        for (Goods goods : goodsList) {
            if (goods.name.equals(name)) {
                return name;
            }
        }

        return null;
    }


}

class Person {
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String shopping(Market market, String goodsName) {
        return market.sell(goodsName);
    }
}

public class _9 {
    public static void main(String[] args) {
        Market market = new Market();
        market.setName("大张超市");
        Goods g1 = new Goods("冰激凌");
        Goods g2 = new Goods("矿泉水");
        Goods[] goods = {g1, g2};
        market.setGoodsList(goods);

        Person p1 = new Person();
        p1.setName("王一博");

        String target = p1.shopping(market, "冰激凌");
        if (target == null) {
            System.out.println("没买到");
        } else {
            System.out.println(p1.getName() + "在" + market.getName() + "买到了" + target);
        }
    }
}
