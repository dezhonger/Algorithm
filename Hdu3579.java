package com.netease.music.algorithm.math;

import java.util.Scanner;

/**
 * Created by dezhonger on 2019/3/30
 * <p>
 * 线性同余方程 ax ≡ b (mod c)
 * <p>
 * 方程ax + by = c与方程 ax ≡ c(mod b)等价，有解的充分条件是gcd(a, b) | c
 *
 *
 * http://acm.hdu.edu.cn/showproblem.php?pid=3579，求线性同余方程组，模数不互质
 * 可以作为模板使用
 */
public class Hdu3579 {


    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }


    /**
     * ax+by = gcd(a, b)
     *
     * @param a
     * @param b
     * @return result[0] = gcd(a, b), result[1] = x, result[2] = y;
     */
    public static long[] exgcd(long a, long b) {
        long ans;
        long[] result = new long[3];
        if (b == 0) {
            result[0] = a;
            result[1] = 1;
            result[2] = 0;
            return result;
        }
        long[] temp = exgcd(b, a % b);
        ans = temp[0];
        result[0] = ans;
        result[1] = temp[2];
        result[2] = temp[1] - (a / b) * temp[2];
        return result;
    }


    static long[] m = new long[10];
    static long[] r = new long[10];

    /**
     * 不互质的情况求解
     *
     * @param n
     * @return
     */
    public static long chinaRemain(int n) {
        long a, b, c, c1, c2, x, y, d, N;
        a = m[0];
        c1 = r[0];
        for (int i = 1; i < n; i++) {
            b = m[i];
            c2 = r[i];
            long[] exgcd = exgcd(a, b);
            d = exgcd[0];
            x = exgcd[1];
            y = exgcd[2];
            c = c2 - c1;
            if (c % d != 0) return -1;
            long b1 = b / d;
            x = ((c / d * x) % b1 + b1) % b1;
            c1 = a * x + c1;
            a = a * b1;
        }
        if (c1 == 0)//当余数都为0
        {
            c1 = 1;
            for (int i = 0; i < n; i++)
                c1 = c1 * m[i] / gcd(c1, m[i]);
        }
        return c1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        int n;
        for (int t = 1; t <= T; t++) {
            n = scanner.nextInt();
            for (int i = 0; i < n; i++) m[i] = scanner.nextInt();
            for (int i = 0; i < n; i++) r[i] = scanner.nextInt();
            long result = chinaRemain(n);
            System.out.printf("Case %s: %s", t, result);
            System.out.println();
        }

    }
}
