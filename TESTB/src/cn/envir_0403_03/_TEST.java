package cn.envir_0403_03;

public class _TEST {
    public static void main(String[] args) {
        int[][] arr = new int[10][10];
        int i, j;
        int sum;
        for (i = 0; i < arr.length; i++) {
            arr[i][0] = i;

            for (j = 1; j <= i; j++) {
                arr[i][j] = j;
                sum = (arr[i][0] * arr[i][j]);
                System.out.print(arr[i][0] + "*" + arr[i][j] + "=" + sum + "\t");
            }
            System.out.println(" ");
        }
    }
}
