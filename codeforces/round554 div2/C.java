package com.netease.music.codeforces.round554.div2;

import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/24
 */
public class C {

    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        if (a == b) {
            System.out.println(0);
            return;
        }
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        if (b % a == 0) {
            System.out.println(0);
            return;
        }
        long dif = b - a;
        long resLcm = Long.MAX_VALUE;
        long res = Long.MAX_VALUE;
        for (long k = 1; k * k <= dif; k++) {
            if (dif % k == 0) {
                long i = k;
                if (i == 1) {
                    long r = a * b / (gcd(a, b));
                    if (r < resLcm) {
                        resLcm = r;
                        res = 0;
                    } else if (r == resLcm) {
                        res = Math.min(res, 0);
                    }
                } else {
                    long h = (a + i - 1) / i;
                    long p = h * i - a;
                    long aa = a + p;
                    long bb = b + p;
                    long r = aa * bb / (gcd(aa, bb));
                    if (r < resLcm) {
                        resLcm = r;
                        res = p;
                    } else if (r == resLcm) {
                        res = Math.min(res, p);
                    }
                }

                i = dif / i;
                if (i == 1) {
                    long r = a * b / (gcd(a, b));
                    if (r < resLcm) {
                        resLcm = r;
                        res = 0;
                    } else if (r == resLcm) {
                        res = Math.min(res, 0);
                    }
                } else {
                    long h = (a + i - 1) / i;
                    long p = h * i - a;
                    long aa = a + p;
                    long bb = b + p;
                    long r = aa * bb / (gcd(aa, bb));
                    if (r < resLcm) {
                        resLcm = r;
                        res = p;
                    } else if (r == resLcm) {
                        res = Math.min(res, p);
                    }
                }


            }
        }
//
//
//        long h = (a + dif - 1) / dif;
//        long p = h * dif - a;
//        System.out.println(p);
//        System.out.println(resLcm);
        System.out.println(res);

    }
}
