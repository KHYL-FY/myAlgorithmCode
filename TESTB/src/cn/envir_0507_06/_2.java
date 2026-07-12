package cn.envir_0507_06;

interface UsbInterface {
    void service();
}

class UDisk implements UsbInterface {
    @Override
    public void service() {
        System.out.println("连接usb接口,开始传输数据");
    }
}

class UsbMouse implements UsbInterface {
    @Override
    public void service() {
        System.out.println("连接usb接口,开始操作鼠标");
    }
}

class UsbFan implements UsbInterface {
    @Override
    public void service() {
        System.out.println("连接USB接口,开始传送凉风");
    }
}

class UsbDemo {
    public UDisk a = new UDisk();
    public UsbMouse b = new UsbMouse();
    public UsbFan c = new UsbFan();

    public void test() {
        a.service();
        b.service();
        c.service();
    }
}


public class _2 {
    public static void main(String[] args) {
        UsbDemo a = new UsbDemo();

        a.test();
    }
}
