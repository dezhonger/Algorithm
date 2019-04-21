package com.netease.music.leetcode.contest.gaoxiaobei;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/4/21
 */
public class B {
    public static void main(String[] args) {
        B b = new B();
        b.smallestEquivalentString("parker", "morris", "parser");
        b.smallestEquivalentString("hello", "world", "hold");
        b.smallestEquivalentString("leetcode", "programs", "sourcecode");
    }

    int[] father = new int[26];

    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }

    void merge(int x, int y) {
        father[y] = x;
    }

    public String smallestEquivalentString(String A, String B, String S) {
        for (int i = 0; i < father.length; i++) father[i] = i;

        List<List<Character>> list = new ArrayList<>();
        for (int i = 0; i < 26; i++) list.add(new ArrayList<>());

        for (int i = 0; i < A.length(); i++) {
            char a = A.charAt(i);
            char b = B.charAt(i);
            int x = find(a - 'a');
            int y = find(b - 'a');
            if (x != y) merge(x, y);
        }
        for (int i = 0; i < 26; i++) {
            int tmp = find(i);
            List<Character> characters = list.get(tmp);
            characters.add((char) (i + 'a'));
        }
        for (int i = 0; i < list.size(); i++) {
            Collections.sort(list.get(i));
        }
//        System.out.println(list);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
//            int tmp = find(S.charAt(i) - 'a');
            for (int j = 0; j < 26; j++) {
                List<Character> characters = list.get(j);
                if (characters.contains(S.charAt(i))) {
                    sb.append(characters.get(0));
                    break;

                }
            }


        }
//        System.out.println(sb.toString());
        return sb.toString();
    }
}
