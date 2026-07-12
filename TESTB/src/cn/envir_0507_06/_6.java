package cn.envir_0507_06;

interface Instrument {
    void makeSound(String name);
}

class Erhu implements Instrument {
    @Override
    public void makeSound(String name) {
        System.out.println(name + "弹奏二胡");
        ;
    }
}

class Piano implements Instrument {
    @Override
    public void makeSound(String name) {
        System.out.println(name + "弹奏钢琴");
        ;
    }
}

class Violin implements Instrument {
    @Override
    public void makeSound(String name) {
        System.out.println(name + "弹奏小提琴");
        ;
    }
}

class Musician {
    private String name;

    Musician() {
    }

    ;

    Musician(String name) {
        this.name = name;
    }

    public void play(Instrument i) {
        i.makeSound(name);
    }
}

public class _6 {
    public static void main(String[] args) {
        Musician m = new Musician("阿炳");
        Erhu a = new Erhu();
        m.play(a);
        Piano b = new Piano();
        m.play(b);
        Violin c = new Violin();
        m.play(c);
    }
}
