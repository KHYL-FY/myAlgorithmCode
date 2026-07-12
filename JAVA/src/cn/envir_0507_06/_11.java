package cn.envir_0507_06;

interface NetWork {
    void networkConn();
}

interface TakePictures {
    void takePicture();
}

interface Play {
    void play(String content);
}

// 实验11 手机功能模拟
abstract class HandSet {
    private String brand;
    private String type;

    public HandSet() {
    }

    public HandSet(String brand, String type) {
        this.brand = brand;
        this.type = type;
    }

    public void showInfo() {
        System.out.println("这是一款型号为" + type + "的" + brand + "的手机!");
    }

    public abstract void call();

    public abstract void sendInfo();

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}

class CommonHandSet extends HandSet implements Play {
    public CommonHandSet() {
    }

    public CommonHandSet(String brand, String type) {
        super(brand, type);
    }

    @Override
    public void call() {
        System.out.println("语音通话...");
    }

    @Override
    public void sendInfo() {
        System.out.println("发送文字信息..");
    }

    @Override
    public void play(String content) {
        System.out.println("播放" + content);
    }
}

class AptitudeHandSet extends HandSet implements Play, NetWork, TakePictures {
    public AptitudeHandSet() {
    }

    public AptitudeHandSet(String brand, String type) {
        super(brand, type);
    }

    @Override
    public void call() {
        System.out.println("视频通话..");
    }

    @Override
    public void sendInfo() {
        System.out.println("发送图文彩信....");
    }

    @Override
    public void play(String content) {
        System.out.println("正在播放" + content);
    }

    @Override
    public void networkConn() {
        System.out.println("成功接入网络..");
    }

    @Override
    public void takePicture() {
        System.out.println("咔嚓.....拍照成功!");
    }
}

public class _11 {
    public static void main(String[] args) {
        System.out.println("--------普通手机---");
        CommonHandSet chs = new CommonHandSet("诺基亚", "N73");
        chs.showInfo();
        chs.sendInfo();
        chs.call();
        chs.play("歌曲《东方红》");

        System.out.println("------智能手机--------");
        AptitudeHandSet ahs = new AptitudeHandSet("华为", "Mate40");
        ahs.showInfo();
        ahs.sendInfo();
        ahs.call();
        ahs.networkConn();
        ahs.takePicture();
        ahs.play("电视剧:《漂洋过海来看你》");
    }
}
