package com.netease.music.codeforces.round553.div2;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/19
 */
public class D {
    static long mod = 10_0000_0007;
    static long[] index = new long[62];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long l = scanner.nextLong();
        long r = scanner.nextLong();
        long s1 = cal(r);
        long s2 = cal(l - 1);
        long s = s1 - s2;
        if(s < 0) s += mod;
        System.out.println(s);


    }
    static long cal(long a) {
        if (a == 0) return 0;
        long[] jiou = new long[]{1, 0};
        long x = 1;
        long cnt = 1;
        int f = 1;
        while(true) {
            x = x << 1;
            if (cnt + x <= a) {
                cnt += x;
                jiou[f] += x;
                f = 1 - f;
            } else {
                jiou[f] += a - cnt;
                break;
            }
        }
        long jicnt = jiou[0];
        BigInteger jisum = new BigInteger(jicnt + "").multiply(new BigInteger((jicnt ) + ""));
        long sum1 = jisum.mod(new BigInteger(mod + "")).longValue();

        long oucnt = jiou[1];
        BigInteger ousum = new BigInteger(oucnt + "").multiply(new BigInteger((oucnt) + ""));
        ousum = ousum.add(new BigInteger(oucnt + ""));
        long sum2 = ousum.mod(new BigInteger(mod + "")).longValue();
        return (sum1 + sum2) % mod;
    }

}
