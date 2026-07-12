package cn.envir_0326_02.A;

public class E
{
    public static void main(String[] args) {
        int sum = 0;
        int n = 0;

        while (sum + (n + 1) < 8888) {
            n++;
            sum += n;
        }
        System.out.println("满足1+2+3+...+n < 8888的最大正整数n = " + n);
    }
}
