package cn.envir_0514_07._15;

class NoAgeException extends Exception {


    public NoAgeException() {
        super();
    }

    public NoAgeException(String message) {
        super(message);
    }
}

class Person {
    private String name;
    private int age;

    public Person(String name, int age) throws NoAgeException {
        if (age < 0 || age > 200) {
            throw new NoAgeException(age + ",年龄数值非法");

        }
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}

public class _15 {
    public static void main(String[] args) {
        try {
            Person a = new Person("张三", 25);
//            System.out.println("over");
            System.out.println(a);
        } catch (NoAgeException e) {
            e.printStackTrace();
        }
        System.out.println("over");

    }
}
