package cn.envir_0326_02.A;

public class J {
    public static void main(String[] args) {

        int sum = 0;
        for(int i = 2;i <= 2000; i++){
            sum = 0;
            for(int j = 1; j <= i - 1; j++){
                if(i % j == 0){
                    sum += j;
                }
            }

            if(sum == i){
                System.out.println(i+"是一个完数");
            }
        }
    }
}
