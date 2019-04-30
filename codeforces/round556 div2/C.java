//package com.netease.music.codeforces.round556.div2;

import java.util.Arrays;
import java.util.Scanner;


/**
 * Created by dezhonger on 2019/4/29
 */
public class B {

//    public static boolean isPrime(int x) {
//        if (x < 2) return false;
//        for (long i = 2; i * i <= x; i++) {
//            if (x % i == 0) {
//                return false;
//            }
//        }
//        return true;
//    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        int c1 = 0;
        int c2 = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
            if (a[i] == 1) c1++;
            else c2++;
        }
        int[] re = new int[n];
        if (c1 == 0) {
            Arrays.fill(re, 2);
//
//            System.out.println(1);
        } else {
            if (c2 == 0) {
                Arrays.fill(re, 1);
                int r = 0;
//                for (int i = 3; i <= n; i += 2) {
//                    if (isPrime(i)) {
//                        r++;
//                    }
//                }
//                System.out.println(r);
            } else {
                re[0] = 2;
                re[1] = 1;

//                int r = 2;
//                int s = 3;
//                int[] b = new int[n + 1];
//                b[1] = 2;
//                b[2] = 1;
                c1--;
                c2--;

                for (int i = 2; i < n; i++) {
                    if (c2 > 0) {
//                        s+=2;
                        c2--;
                        re[i] = 2;
                    } else {
//                        s++;
                        c1--;
                        re[i] = 1;
                    }
//                    if (isPrime(s)) r++;
                }
//                System.out.println(r);
            }

        }
        for (int i = 0; i < n; i++) {
            if (i == 0) System.out.print(re[i]);
            else System.out.print(" " + re[i]);
        }
        System.out.println();
    }
}