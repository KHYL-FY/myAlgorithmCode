package cn.lyh;

interface Film {
    void film();
}

interface TelePlay {
    void telePlay();
}

interface Sing {
    void sing();
}

class Actor implements Film, TelePlay, Sing {
    private String name;

    public Actor(String name) {
        this.name = name;
    }

    void show() {
        System.out.println("大家好, 我是" + name + "!");
    }

    @Override
    public void film() {
        System.out.println("我能演电影!");
    }

    @Override
    public void telePlay() {
        System.out.println("我能演电视剧!");
    }

    @Override
    public void sing() {
        System.out.println("我会唱歌!");
    }
}

public class _02 {
    public static void main(String[] args) {
        Actor a = new Actor("杨幂");
        a.show();
        a.film();
        a.telePlay();
        a.sing();
    }
}
