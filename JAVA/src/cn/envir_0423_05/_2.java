package cn.envir_0423_05;

class Student {
    private String name;
    private int age;

    Student() {
    }

    Student(String name, int age) {
        setName(name);
        setAge(age);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void show() {
        System.out.println("姓名: " + name);
        System.out.println("年龄: " + age);
    }

}

class Undergraduate extends Student {
    private String degree;

    Undergraduate() {
    }

    Undergraduate(String name, int age, String degree) {
        super(name, age);
        setDegree(degree);
    }

    public String getDegree() {
        return degree;
    }

    public void setDegree(String degree) {
        this.degree = degree;
    }

    @Override
    public void show() {
        super.show();
        System.out.println("学位:　" + degree);
    }
}

public class _2 {
    public static void main(String[] args) {
        Student a = new Student("冯绍峰", 23);
        a.show();
        Undergraduate b = new Undergraduate("赵丽颖", 27, "学士");
        b.show();

    }
}
