package cn.envir_0514_07._10;


public class _10 {
    public static void main(String[] args) {
        // 第一阶段
        int a = 10;
        int b = 0;
        int[] arr = {1, 2, 3};
        try {

            System.out.println(a / b);
            System.out.println(arr[3]);

        } catch (ArithmeticException e) {
            System.out.println("除数不能为0");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("数组越界");
        }
        // 第二阶段
        System.out.println("over");


    }
}
