package cn.envir_0326_02.A;

public class L {
    public static void main(String[] args) {
                int count = 0;

                for (int hen = 0; hen <= 20; hen++) {
                    for (int rooster = 0; rooster <= 33; rooster++) {
                        int chick = 100 - hen - rooster;
                        if (chick >= 0 && chick % 3 == 0) {
                            int totalPrice = 5 * hen + 3 * rooster + chick / 3;
                            if (totalPrice == 100) {
                                count++;
                                System.out.printf("方案%d: 母鸡=%d只, 公鸡=%d只, 小鸡=%d只  共%d只, %d钱\n",
                                        count, hen, rooster, chick,
                                        hen + rooster + chick, totalPrice);
                            }
                        }
                    }
                }
                System.out.println("共有 " + count + " 种买法");
            }
        }
