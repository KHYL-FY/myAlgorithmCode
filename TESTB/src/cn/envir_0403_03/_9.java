package cn.envir_0403_03;

public class _9 {
    public static void main(String[] args) {
        int[][] table = new int[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                table[i][j] = (i + 1) * (j + 1);
            }
        }

        System.out.println("九九乘法表：");

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print((j + 1) + "×" + (i + 1) + "=" + table[i][j] + "\t");
            }
            System.out.println();
        }
    }
}

