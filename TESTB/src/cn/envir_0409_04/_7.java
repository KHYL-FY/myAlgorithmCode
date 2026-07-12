package cn.envir_0409_04;

class Student {
    private int age;
    private String name;
    private String sex;

    Student() {
    }

    Student(String name, int age, String sex) {
        this.name = name;
        this.age = age;
        this.sex = sex;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", sex='" + sex + '\'' +
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


    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void showInfo() {
        System.out.println("姓名：" + name + "，性别：" + sex + "，年龄：" + age);
    }
}

public class _7 {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.setName("贾玲");
        s1.setAge(21);
        s1.setSex("女");
        s1.showInfo();

        Student s2 = new Student("岳云鹏", 26, "男");
        System.out.println(s2.toString());
    }
}
