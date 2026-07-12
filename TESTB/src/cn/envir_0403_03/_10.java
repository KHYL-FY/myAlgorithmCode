package cn.envir_0403_03;

public class _10 {
    public static void main(String[] args) {
        int rows = 10;
        int[][] a = new int[rows][];

        for (int i = 0; i < rows; i++) {
            a[i] = new int[i + 1];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                }
            }
        }

        System.out.println("杨辉三角：");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
    }
}

