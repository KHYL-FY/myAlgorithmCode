package cn.envir_0409_04;

class Account {
    public static String bankName;
    private double balance;
    private String accountName;
    private String accountPass;

    Account() {
    }

    Account(double balance, String accountName, String accountPass) {
        this.balance = balance;
        this.accountName = accountName;
        this.accountPass = accountPass;
    }

    public static void welcome() {
        System.out.println("招商银行欢迎您的光临");
    }

    public static void sayBye() {
        System.out.println("招商银行感谢您的光临,欢迎下次再来");
    }

    public boolean deposit(String accountName, String accountPass, double money) {
        if (this.accountPass.equals(accountPass) && this.accountName.equals(accountName)) {
            if (money > 0) {
                balance += money;
                System.out.println(accountName + "已经成功存入" + money + "元,目前的金额为" + balance);
                return true;
            } else {
                System.out.println("存款金额错误");
                return false;
            }
        } else {
            System.out.println("账号密码输入错误");
            return false;
        }
    }

    public boolean withdraw(String accountName, String accountPass, double money) {
        if (this.accountPass.equals(accountPass) && this.accountName.equals(accountName)) {
            if (balance >= money) {
                balance -= money;
                System.out.println(accountName + "已经成功取出" + money + "元,目前的金额为" + balance);
                return true;
            } else {
                System.out.println("取款金额错误");
                return false;
            }
        } else {
            System.out.println("账号密码输入错误");
            return false;
        }
    }

    public String getAccountName() {
        return accountName;
    }

    public void setAccountName(String accountName) {
        this.accountName = accountName;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getAccountPass() {
        return accountPass;
    }

    public void setAccountPass(String accountPass) {
        this.accountPass = accountPass;
    }
}

public class _11 {
}
