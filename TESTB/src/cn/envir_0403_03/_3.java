package cn.envir_0403_03;

public class _3 {
    public static void main(String[] args) {
        int[] arr = {11, 34, 47, 19, 5, 87, 63, 88};

        System.out.println("原数组如下");
        for (int i = 0; i < 8; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("\n逆序数组如下");
        for (int i = 7; i >= 0; i--) {
            System.out.print(arr[i] + " ");
        }
    }
}
