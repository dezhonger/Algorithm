package com.netease.music.codeforces.round553.div2;

import java.util.Arrays;
import java.util.Scanner;

/**C
 * Created by dezhonger on 2019/4/19
 */
public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        P[] p = new P[n];
        long sum1 =0 ;
        long sum2 = 0;
        for (int i = 0; i < n; i++) {
            long a = scanner.nextInt();
            long b = scanner.nextInt();
            sum1 += a;
            sum2 += b;
            p[i] = new P(a, b);
        }
        Arrays.sort(p);
        long s = 0;
        for (int i = 0; i < n; i++) {
            s = s + p[i].c * (i + 1);
        }

        s -= sum1;
        s += sum2 * n;
        System.out.println(s);

    }
}

class P implements Comparable<P> {
    long a, b;
    long c;

    public P(long a, long b) {
        this.a = a;
        this.b = b;
        this.c = a - b;
    }

    @Override
    public int compareTo(P o) {
        return Long.compare(o.c, c);
    }
}
