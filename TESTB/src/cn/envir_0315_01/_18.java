package cn.envir_0315_01;
import java.util.Scanner;

public class _18 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] num = new int[4];

        for(int i = 1; i <= 3; i++){
            num[i] = sc.nextInt();
        }
        int t = 0;
        for(int i = 1; i < 3; i++){
            for(int j = i + 1; j <= 3; j++){
                if(num[i] > num[j]){
                    t = num[i];
                    num[i] = num[j];
                    num[j] = t;
                }
            }
        }

        for(int i = 1; i <= 3; i++){
            System.out.print(num[i]+" ");
        }

    }
}
