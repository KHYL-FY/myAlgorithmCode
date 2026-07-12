package cn.envir_0409_04;

class Manager {
    private int age;
    private String name;
    private String sex;
    private double sal;

    Manager() {
    }

    Manager(String name, int age, String sex, double sal) {
        this.name = name;
        this.age = age;
        this.sex = sex;
        this.sal = sal;
    }

    @Override
    public String toString() {
        return "Manager{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", sex='" + sex + '\'' +
                ", sal=" + sal +
                '}';
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getSal() {
        return sal;
    }

    public void setSal(double sal) {
        this.sal = sal;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String judge() {
        return age < 40 ? name + "要加班" : name + "不用加班";
    }
}


public class _6 {
    public static void main(String[] args) {
        Manager a = new Manager();
        a.setName("佟丽娅");
        a.setAge(27);
        a.setSex("女");
        a.setSal(8888.88);

        System.out.println(a.toString());
        System.out.println(a.judge());

        Manager b = new Manager("蔡徐坤", 35, "男", 29999.99);

        System.out.println(b.toString());
        System.out.println(b.judge());
    }
}
