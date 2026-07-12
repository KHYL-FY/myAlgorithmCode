package cn.lyh;

interface Instrument {
    void makeSound(String name);
}

class Erhu implements Instrument {
    @Override
    public void makeSound(String name) {
        System.out.println(name + "弹奏二胡!");
    }
}

class Piano implements Instrument {
    @Override
    public void makeSound(String name) {
        System.out.println(name + "弹奏钢琴!");
    }
}

class Violin implements Instrument {
    @Override
    public void makeSound(String name) {
        System.out.println(name + "弹奏小提琴!");
    }
}

class Musician {
    private String name;

    public Musician(String name) {
        this.name = name;
    }

    void Musician() {
    }

    public void play(Instrument i) {
        i.makeSound(this.name);
    }
}


public class _03 {
    public static void main(String[] args) {
        Musician m = new Musician("阿炳");
        Instrument i = new Erhu();
        m.play(i);
        Instrument j = new Piano();
        m.play(j);
        Instrument k = new Violin();
        m.play(k);
    }
}
