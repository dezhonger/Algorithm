package com.netease.music.codeforces.round551.div2;

import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/13
 */
public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int h = scanner.nextInt();
        int[] marr = new int[m];
        int[] narr = new int[n];
        for (int i = 0; i < m; i++) marr[i] = scanner.nextInt();
        for (int i = 0; i < n; i++) narr[i] = scanner.nextInt();
        int[][] harr = new int[n][m];
        int[][] r = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                harr[i][j] = scanner.nextInt();
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (harr[i][j] == 0) r[i][j] = 0;
                else {
                    int row = narr[i];
                    int column = marr[j];
                    harr[i][j] = Math.min(row, column);
                }
                if (j == m - 1) {
                    System.out.println(harr[i][j]);
                } else {

                    System.out.print(harr[i][j] + " ");
                }
            }
        }
    }
}
