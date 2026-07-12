package cn.envir_0326_02.A;

public class K {
    public static void main(String[] args) {

        for(int i = 1; i <= 3; i++){
            for(int j = 3; j > i; j--){
                System.out.print(" ");
            }
            for(int j = 1; j <= 2*i-1; j++){
                System.out.print("*");
            }
            System.out.println("");
        }


    }
}
