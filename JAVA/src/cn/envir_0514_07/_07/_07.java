package cn.envir_0514_07._07;

interface Person {
    void study();
}

class PersonDemo {

    public void method(Person p) {
        p.study();
    }
}

public class _07 {
    public static void main(String[] args) {
        PersonDemo pd = new PersonDemo();
        pd.method(new Person() {
            @Override
            public void study() {
                System.out.println("好好学习JAVA,月薪上万元");
            }
        });

    }
}
