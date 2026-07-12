package cn.envir_0409_04;

class Students {
    private String name;
    private int age;

    public Students() {
    }

    public Students(String name, int age) {
        this.name = name;
        this.age = age;
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

    @Override
    public String toString() {
        return "Students [姓名=" + name + ", 年龄=" + age + "]";
    }
}

class StudentClass {
    private String name;
    private int number;
    private Students[] member = new Students[50];

    public StudentClass() {
    }

    public StudentClass(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public Students[] getMember() {
        return member;
    }

    public void addStudent(Students s) {
        if (number < 50) {
            member[number] = s;
            number++;
        } else {
            System.out.println("本班已经有50名学生，无法添加。");
        }
    }

    public void showMsg() {
        System.out.println("班级名称：" + name);
        System.out.println("班级学生人数：" + number);
        System.out.println("==========学生信息==========");
        for (int i = 0; i < number; i++) {
            System.out.println(member[i].toString());
        }
    }
}

public class _10 {
    public static void main(String[] args) {
        StudentClass sc = new StudentClass();
        sc.setName("Java面向对象一班");

        Students s1 = new Students();
        s1.setName("小明");
        s1.setAge(18);

        Students s2 = new Students("小红", 19);
        Students s3 = new Students("小刚", 20);

        sc.addStudent(s1);
        sc.addStudent(s2);
        sc.addStudent(s3);

        sc.showMsg();
    }
}
