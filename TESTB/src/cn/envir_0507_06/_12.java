package cn.envir_0507_06;

// 实验12 物流快递系统
interface GPS {
    String showXY();
}

interface CarCare {
    void upKeep();
}

class Phone implements GPS {
    @Override
    public String showXY() {
        return "249,251";
    }
}

abstract class Transportation {
    private String No;
    private String model;
    private String admin;

    public Transportation() {
    }

    public Transportation(String No, String model, String admin) {
        this.No = No;
        this.model = model;
        this.admin = admin;
    }

    public abstract void transport();

    public String getNo() {
        return No;
    }

    public void setNo(String no) {
        No = no;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getAdmin() {
        return admin;
    }

    public void setAdmin(String admin) {
        this.admin = admin;
    }
}

class SFTran extends Transportation implements CarCare {
    public SFTran() {
    }

    public SFTran(String No, String model, String admin) {
        super(No, model, admin);
    }

    @Override
    public void transport() {
        System.out.println("运输中。。。");
    }

    @Override
    public void upKeep() {
        System.out.println("货物运输车辆保养完毕！");
    }
}

class SendTask {
    private String No;
    private double weight;

    public SendTask() {
    }

    public SendTask(String No, double weight) {
        this.No = No;
        this.weight = weight;
    }

    public void sendBefore() {
        System.out.println("订单开始处理,仓库验货中。。。");
        System.out.println("货物的重量:" + weight);
        System.out.println("货物检验完成。");
        System.out.println("货物装车完成。");
        System.out.println("快递单号:" + No);
    }

    public void send(Transportation t, GPS tools) {
        System.out.println("运货人:" + t.getAdmin() + ",驾驶编号为" + t.getNo() + "的" + t.getModel() + "运送货物!");
        t.transport();
        System.out.println("货物的当前坐标为:" + tools.showXY());
        System.out.println("---");
    }

    public void sendAfter(Transportation t) {
        System.out.println("货物运输任务已完成!");
        System.out.println("运货人:" + t.getAdmin() + "所驾驶的编号为" + t.getNo() + "的" + t.getModel() + "已经归还!");
    }

    public String getNo() {
        return No;
    }

    public void setNo(String no) {
        No = no;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
}


public class _12 {
    public static void main(String[] args) {
        SendTask st = new SendTask("SF62225", 10.25);
        st.sendBefore();

        SFTran t = new SFTran("SF025", "五菱之光", "岳云鹏");
        Phone ph = new Phone();

        st.send(t, ph);
        st.sendAfter(t);
        t.upKeep();
    }
}
