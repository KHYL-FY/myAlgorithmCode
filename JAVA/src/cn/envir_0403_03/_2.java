package cn.envir_0403_03;

public class _2 {
    public static void main(String[] args) {
        int a = 0, b = 1, c = 0;

        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 6; j++) {
                c = a + b;
                b = a;
                a = c;
                System.out.printf("%-8d", c);
            }
            System.out.print("\n");
        }
    }
}
