package com.netease.music.codeforces.round554.div2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/24
 */
public class B {

    private static int f(int x, List<Integer> list, int c) {
        String s = Integer.toBinaryString(x);
        int index = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return -1;
        } else {
            if (c == 1) {
                list.add(s.length() - index);
            }
            return (1 << (s.length() - index)) - 1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
//        System.out.println(f(n));
//        System.out.println(Integer.toBinaryString(39));
////        System.out.println(Integer.toBinaryString(39^31));
////        System.out.println(39^31);


        List<Integer> list = new ArrayList<>();
        int turn = 1;
        int cnt = 0;
        while (true) {
            if (turn == 1) {
                int tmp = f(n, list, 1);
                if (tmp == -1) {
                    break;
                } else {
                    cnt++;
                    n = n ^ tmp;
                }
            } else {
                if (f(n, list, 0) == -1) break;
                n++;
                cnt++;
            }
            turn = 1 - turn;
        }
        System.out.println(cnt);
        for (int i = 0; i < list.size(); i++) {
            if (i != list.size() - 1) {
                System.out.print(list.get(i) + " ");
            } else {
                System.out.println(list.get(i));
            }
        }
    }
}
