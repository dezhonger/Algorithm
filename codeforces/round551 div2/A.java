package com.netease.music.codeforces.round551.div2;

import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/13
 */
public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        int mi = Integer.MAX_VALUE;
        int result = -1;
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a < t) {
                int x = (t - a + b - 1) / b;
                a = a + x * b;
            }
            if (a < mi) {
                mi = a;
                result = i + 1;
            }
        }
        System.out.println(result);
    }
}
