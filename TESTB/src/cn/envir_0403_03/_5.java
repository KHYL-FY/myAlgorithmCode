package cn.envir_0403_03;

public class _5 {
    public static void main(String[] args) {
        int[] arr = {11, 34, 47, 19, 5, 87, 63, 88};

        System.out.println("原数组如下");
        for (int i = 0; i < 8; i++) {
            System.out.print(arr[i] + " ");
        }

        for (int i = 0; i < 7; i++) {
            for (int j = i; j < 7; j++) {
                if (arr[i] > arr[j]) {
                    int t = arr[j];
                    arr[j] = arr[i];
                    arr[i] = t;
                }
            }
        }
        System.out.println("\n排序后数组如下");
        for (int i = 0; i <= 7; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
