package com.netease.music.loj;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by dezhonger on 2019/5/3
 * <p>
 * 区间dp, 每行分别处理再求和
 */
public class P1005 {

    static int n, m;
    static long[][] a;



    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        a = new long[n + 1][m + 1];

        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = scanner.nextLong();
        BigInteger res = BigInteger.ZERO;
        //每行分别处理
        for (int k = 1; k <= n; k++) {
            BigInteger[][] dp = new BigInteger[m + 1][m + 1];
            for (int len = 1; len <= m; len++) {
                BigInteger wb = new BigInteger(2 + "").pow(m - len + 1);
                for (int i = 1; i <= m; i++) {
                    int j = i + len - 1;
                    if (j > m) continue;
                    if (len == 1) {
                        dp[i][i] = wb.multiply(new BigInteger(a[k][i] + ""));
                    } else {

                        BigInteger w1 = dp[i + 1][j].add(wb.multiply(new BigInteger(a[k][i] + "")));
                        BigInteger w2 = dp[i][j - 1].add(wb.multiply(new BigInteger(a[k][j] + "")));
                        BigInteger wv = w1.compareTo(w2) > 0 ? w1 : w2;
                        dp[i][j] = wv;
                    }

                }
            }
            res = res.add(dp[1][m]);
        }
        System.out.println(res.toString());
    }
}
