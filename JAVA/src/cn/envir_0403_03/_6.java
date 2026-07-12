package cn.envir_0403_03;

import java.util.Scanner;

public class _6 {
    public static void main(String[] args) {
        int[] arr = {11, 34, 47, 19, 5, 87, 63, 88};

        System.out.println("原数组如下");
        for (int i = 0; i < 8; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("\n输入要查找的数");
        Scanner sc = new Scanner(System.in);
        int findNum = sc.nextInt();
        int findP = -1;
        for (int i = 0; i <= 7; i++) {
            if (arr[i] == findNum) {
                findP = i;
                break;
            }
        }
        if (findP == -1) {
            System.out.println("未找到该数字");
        } else {
            System.out.println("该数字在" + findP);
        }
    }
}
