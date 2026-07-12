package cn.envir_0514_07._16;

import java.util.Scanner;

class AgeException extends Exception {
    public AgeException() {
        super("年龄应该在18-60之间");
    }
}

class Person {
    private int age;

    public int getAge() {
        return age;
    }

    public void setAge(int age) throws AgeException {
        if (age < 18 || age > 60) {
            throw new AgeException();
        }
        this.age = age;
    }
}

public class _16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Person p = new Person();

        System.out.println("请输入您的年龄:");
        int age = sc.nextInt();

        try {
            p.setAge(age);
            System.out.println("你的年龄合适,可应征入伍!");
        } catch (AgeException e) {
            e.printStackTrace();
        }

        sc.close();
    }
}
