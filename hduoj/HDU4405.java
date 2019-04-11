package com.netease.music.hdu;

import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/11
 * <p>
 * dp[i]:从i点出发到终点的期望次数
 * dp[x] = dp[v[x]]
 * <p>
 * dp[n] = 0
 */
public class HDU4405 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (n == 0 && m == 0) break;
            int[] v = new int[n + 10];
            double[] dp = new double[n + 10];
            for (int i = 0; i < m; i++) {
                int tmp1 = scanner.nextInt();
                int tmp2 = scanner.nextInt();
                v[tmp1] = tmp2;
            }

            for (int i = n - 1; i >= 0; i--) {
                if (v[i] == 0) {
                    double s = 0;
                    for (int k = 1; k <= 6; k++) {
                        s += dp[i + k];
                    }
                    dp[i] = s / 6 + 1;
                } else {
                    dp[i] = dp[v[i]];
                }
            }
            DecimalFormat df = new DecimalFormat( "0.0000");
            System.out.println(df.format(dp[0]));
        }
    }
}
