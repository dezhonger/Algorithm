package com.netease.music.codeforces.round551.div2;

import java.util.Scanner;
import java.util.Stack;

/**
 * Created by dezhonger on 2019/4/13
 */
public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.valueOf(scanner.next());
        String s = scanner.next();
        int zuo = 0;
        int you = 0;
        int wenhao = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') zuo++;
            else if (s.charAt(i) == ')') you++;
            else wenhao++;
        }
        if (n % 2 == 1) {
            System.out.println(":(");
            return;
        }
        if (zuo > n / 2 || you > n / 2) {
            System.out.println(":(");
            return;
        }

        int remainzuo = n / 2 - zuo;
        int remainyou = n / 2 - you;

//        if (!(s.charAt(0) == '(' && s.charAt(n - 1) == ')')) {
//            System.out.println(":(");
//            return;
//        }
        Stack<Character> stack = new Stack();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != '?') {
                if (s.charAt(i) == '(') {
                    stack.push('(');
                    sb.append('(');
                }
                else {
                    if (stack.empty()) {
                        System.out.println(":(");
                        return;
                    }
                    stack.pop();
                    sb.append(')');
                    if (i != s.length() - 1 && stack.empty()) {
                        System.out.println(":(");
                        return;
                    }
                }
            } else {
                if (remainzuo > 0) {
                    stack.push('(');
                    sb.append('(');
                    remainzuo--;
                } else {
                    if (stack.empty()) {
                        System.out.println(":(");
                        return;
                    }
                    stack.pop();
                    sb.append(')');
                    if (i != s.length() - 1 && stack.empty()) {
                        System.out.println(":(");
                        return;
                    }
                }
            }

        }

        if (stack.empty()) {
            System.out.println(sb.toString());
        } else {
            System.out.println(":(");
        }

    }
}
