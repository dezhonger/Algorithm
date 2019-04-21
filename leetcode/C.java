package com.netease.music.leetcode.contest.gaoxiaobei;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/4/21
 *
 * https://blog.csdn.net/fangjian1204/article/details/38705867
 */
public class C {
    public static void main(String[] args) {
        System.out.println(new C().longestRepeatingSubstring("abcd"));
        System.out.println(new C().longestRepeatingSubstring("abbaba"));
        System.out.println(new C().longestRepeatingSubstring("aabcaabdaab"));
        System.out.println(new C().longestRepeatingSubstring("aaaaa"));
    }
    private int commonLenght(String s1, String s2) {
//        int length = min(s1.size(), s2.size()), i;
        int length = Math.min(s1.length(), s2.length());
        int i;
        for (i = 0; i < length; i++) {
            if (s1.charAt(i) != s2.charAt(i)) break;
        }
        return i;
    }

    private String LRS(String s) {
        List<String> suffix = new ArrayList<>();
        int i, maxLength = 0;
        for (i = 0; i < s.length(); ++i) {
            suffix.add(s.substring(i));
        }
        Collections.sort(suffix);
        String res = "";
        for (i = 0; i < suffix.size() - 1; ++i) {
            int len = commonLenght(suffix.get(i), suffix.get(i +1));
            if (len > maxLength) {
                maxLength = len;
                res = suffix.get(i).substring(0, len);
            }
        }
        return res;
    }

    public int longestRepeatingSubstring(String S) {
        return LRS(S).length();
    }
}
