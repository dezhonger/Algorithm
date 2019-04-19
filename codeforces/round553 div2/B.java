//package com.netease.music.codeforces.round553.div2;

import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/19
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] a = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        boolean f = true;
        int buxaingtong = 0;
        for (int i = 1; i <= n; i++) {
            int cur = a[i][1];
            boolean ff = true;
            for (int j = 2; j <= m; j++) {
                if (a[i][j] != cur) {
                    ff = false;
                    buxaingtong = i;
                    break;
                }
            }
            if (!ff) {
                f = false;
                break;

            }
        }
        if (f) {
            //all same
            int s = 0;
            for (int i = 1; i <= n; i++) {
                s ^= a[i][1];
            }
            if (s == 0) {
                System.out.println("NIE");
                return;
            } else {
                System.out.println("TAK");
                for (int i = 1; i < n; i++) {
                    System.out.print(1 + " ");
                }
                System.out.println(1);
            }
        } else {
            System.out.println("TAK");

            int s = 0;
            for (int i = 1; i <= n; i++) {
                if (i != buxaingtong) {
                    s ^= a[i][1];
                }
            }
            int lie = 0;
            for (int i = 1; i <= m; i++) {
                if ((s ^ a[buxaingtong][i]) != 0) {
                    lie = i;
                    break;
                }
            }
            for (int i = 1; i < buxaingtong; i++) {
                System.out.print(1 + " ");
            }
            System.out.print(lie);
            if (buxaingtong == n) {
                System.out.println();
            } else {
                System.out.println(" ");
            }
            for (int i = buxaingtong + 1; i <= n; i++) {
                System.out.println(1);
                if (i == n) {
                    System.out.println();
                } else {
                    System.out.println(" ");
                }
            }
        }
    }
}
