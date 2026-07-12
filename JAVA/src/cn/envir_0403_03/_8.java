package cn.envir_0403_03;

public class _8 {
    public static void main(String[] args) {
        int[][] arr = {
                {45, 23, 67, 89},
                {12, 34, 56, 78},
                {91, 5, 33, 27},
                {64, 28, 19, 42}
        };

        int minValue = arr[0][0];
        int minRow = 0;
        int minCol = 0;

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] < minValue) {
                    minValue = arr[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }

        System.out.println("二维数组：");
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println();
        }

        System.out.println("\n最小值：" + minValue);
        System.out.println("所在位置：第" + (minRow + 1) + "行，第" + (minCol + 1) + "列");
        System.out.println("索引：[" + minRow + "][" + minCol + "]");
    }
}
