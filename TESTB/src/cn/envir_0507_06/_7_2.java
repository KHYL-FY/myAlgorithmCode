package cn.envir_0507_06;

// 实验7 USB接口综合案例
interface Usb {
    void turnOn();

    void turnOff();
}

class KeyBoard implements Usb {
    @Override
    public void turnOn() {
        System.out.println("键盘启动");
    }

    @Override
    public void turnOff() {
        System.out.println("键盘关闭");
    }
}

class Mouse implements Usb {
    @Override
    public void turnOn() {
        System.out.println("鼠标启动");
    }

    @Override
    public void turnOff() {
        System.out.println("鼠标关闭");
    }
}

class Computer {
    private Usb[] usbArr = new Usb[4];

    public void add(Usb usb) {
        for (int i = 0; i < usbArr.length; i++) {
            if (usbArr[i] == null) {
                usbArr[i] = usb;
                break;
            }
        }
    }

    public void powerOn() {
        for (Usb usb : usbArr) {
            if (usb != null) {
                usb.turnOn();
            }
        }
        System.out.println("电脑开机成功！");
    }

    public void powerOff() {
        for (Usb usb : usbArr) {
            if (usb != null) {
                usb.turnOff();
            }
        }
        System.out.println("电脑关机成功！");
    }
}

public class _7_2 {
    public static void main(String[] args) {
        Computer computer = new Computer();
        computer.add(new KeyBoard());
        computer.add(new Mouse());
        computer.powerOn();
        computer.powerOff();
    }
}
