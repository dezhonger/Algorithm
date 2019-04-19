package com.netease.music.codeforces.round553.div2;

import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/18
 */
public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.valueOf(scanner.nextInt());
        String s = "ACTG";
        String str = scanner.next();
        int r = Integer.MAX_VALUE;
        for (int i = 4; i <= str.length(); i++) {
            String tmp = str.substring(i - 4, i);
            r = Math.min(r, f(s, tmp));
        }
        System.out.println(r);
    }

    static int f(String s1, String s2) {
        int r =0 ;
        for (int i = 0; i < 4; i++) {
            int a = s1.charAt(i) - s2.charAt(i);
            if (a < 0) a += 26;
            int b = s2.charAt(i) - s1.charAt(i);
            if (b < 0) b += 26;
            r += Math.min(a, b);

        }
        return r;
    }
}
