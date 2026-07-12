package cn.envir_0409_04;

class Employee {
    private int age;
    private String name;
    private String sex;
    private double sal;

    Employee() {
    }

    Employee(String name, int age, String sex, double sal) {
        this.name = name;
        this.age = age;
        this.sex = sex;
        this.sal = sal;
    }

    @Override
    public String toString() {
        return "Employee{" +
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
        return age < 30 ? name + "要加班" : name + "不用加班";
    }
}

public class _5 {
    public static void main(String[] args) {

        Employee a = new Employee();
        a.setName("高圆圆");
        a.setAge(18);
        a.setSex("女");
        a.setSal(8888.88);

        System.out.println(a.toString());
        System.out.println(a.judge());

        Employee b = new Employee("林青霞", 35, "男", 29999.99);

        System.out.println(b.toString());
        System.out.println(b.judge());

    }
}
