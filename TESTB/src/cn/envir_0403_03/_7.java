package cn.envir_0403_03;

import java.util.Arrays;

public class _7 {
    public static int binarySearch(int[] arr, int value) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (value == arr[mid]) {
                return mid;
            } else if (value < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        int[] arr = {11, 34, 47, 19, 5, 87, 63, 88};

        Arrays.sort(arr);
        System.out.print("排序后的数组：");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        int value = 47;
        int find_ = binarySearch(arr, value);

        if (find_ != -1) {
            System.out.println("查找成功！元素 " + value + " 在数组中的索引为：" + find_);
        } else {
            System.out.println("查找失败！元素 " + value + " 不在数组中");
        }
    }


}

