package cn.envir_0326_02.A;

public class I {
    public static void main(String[] args) {

        boolean prime = true;
        for(int n = 200; n <= 300 ;n++){
            prime = true;
            for(int i = 2; i <= (int)Math.sqrt(n); i++){
                if(n % i == 0){
                    prime = false;
                    break;
                }
            }
            if(prime){
                System.out.println(n);
            }
        }
    }
}
