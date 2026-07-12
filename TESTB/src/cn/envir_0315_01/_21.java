package cn.envir_0315_01;

public class _21 {
    public static void main(String[] args) {
        int charASCII = (int)(Math.random()*100);

        char a = (char)charASCII;

        if(a>='A'&&a<='Z'){
            System.out.print(a);
            System.out.println("是大写字母");
        }
        else if (a>='a'&&a<='z') {
            System.out.print(a);
            System.out.println("是小写字母");
        }
        else{
            System.out.print(a);
            System.out.println("不是字母");
        }

    }
}
