package cn.envir_0403_03;

import java.util.Random;

public class _1 {
    public static void main(String[] args) {
        Random random = new Random();

        int[] a = new int[10];

        for (int i = 0; i < 10; i++) {
            a[i] = random.nextInt(100) + 1;
        }
        int maxNum = a[0], maxP = 0;
        System.out.println("产生的10个随机数如下");

        for (int i = 0; i < 9; i++) {
            System.out.print(a[i] + "  ");
            if (maxNum < a[i]) {
                maxNum = a[i];
                maxP = i;
            }
        }

        System.out.println("\n该数组的最大数为" + maxNum);
        System.out.println("最大数的下标为" + maxP);
    }
}
