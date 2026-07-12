package cn.envir_0507_06;

interface Film {
    void film();
}

interface TelePlay {
    void telePlay();
}

interface Sing {
    void sing();
}

class Actor implements Sing, TelePlay, Film {
    private String name;

    Actor(String name) {
        this.name = name;
    }

    @Override
    public void sing() {
        System.out.println("我会唱歌");
    }

    @Override
    public void telePlay() {
        System.out.println("我能演电视剧");
    }

    @Override
    public void film() {
        System.out.println("我能演电影");
    }

    public void show() {
        System.out.println("大家好我是" + name);
        film();
        telePlay();
        sing();
    }
}

public class _5 {
    public static void main(String[] args) {
        Actor a = new Actor("吴彦祖");

        a.show();
    }
}
