package cn.envir_0403_03;

public class _4 {
    public static void main(String[] args) {
        int[] arr = {11, 34, 47, 19, 5, 87, 63, 88};

        System.out.println("原数组如下");
        for (int i = 0; i < 8; i++) {
            System.out.print(arr[i] + " ");
        }

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int t = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = t;
                }
            }
        }
        System.out.println("\n排序后数组如下");
        for (int i = 0; i <= 7; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
