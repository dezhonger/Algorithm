//package com.netease.music.codeforces;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by dezhonger on 2019/5/5
 */
public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int res = n * 3 - 2;
        Set<Integer> set = new HashSet<>();
        int c = 0;
        int[] ka = new int[k + 1];
        for (int i = 1; i <= k; i++) {
            int tmp = scanner.nextInt();
            ka[i] = tmp;
            if (!set.contains(tmp)) c++;
            set.add(tmp);
        }
        res -= c;
        //first pos
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = k; i >= 1; i--) {
            map.put(ka[i], i);
        }
        Map<Integer, Set<Integer>> mp = new HashMap<>();
        for (int i = 1; i <= k; i++) {
            Set<Integer> integers = mp.get(ka[i]);
            if (integers == null) {
                Set<Integer> pos = new HashSet<>();
                pos.add(i);
                mp.put(ka[i], pos);
            } else {
                integers.add(i);
            }
        }

        final int[] need = new int[1];
        mp.forEach((key, val) -> {
            int l = key - 1;
            int r = key + 1;
            Set<Integer> lmp = mp.get(l);
            Set<Integer> rmp = mp.get(r);
            int firstpos = map.get(key);
            if (lmp != null) {
                for (int lv : lmp) {
                    if (lv > firstpos) {
                        need[0]++;
                        break;
                    }
                }
            }
            if (rmp != null) {
                for (int rv : rmp) {
                    if (rv > firstpos) {
                        need[0]++;
                        break;
                    }
                }
            }


        });
        res -= need[0];
//
//        for (int i = 1; i <= n; i++) {
//            Set<Integer> integers = mp.get(i);
//            if (integers != null) {
//                int l = i - 1;
//                int r = i + 1;
//                Set<Integer> lmp = mp.get(l);
//                Set<Integer> rmp = mp.get(r);
//            }
//        }
        System.out.println(res);
    }
}