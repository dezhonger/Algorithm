package com.netease.music.leetcode.contest.gaoxiaobei;

import java.util.Arrays;
import java.util.Stack;

/**
 * Created by dezhonger on 2019/4/21
 */
public class D {
    public static void main(String[] args) {
        D d = new D();
        d.validSubarrays(new int[]{1, 4, 2, 5, 3});
        d.validSubarrays(new int[]{3, 2, 1});
        d.validSubarrays(new int[]{2, 2, 2});
    }
    public int validSubarrays(int[] nums) {
        int[] a = new int[nums.length];
        Arrays.fill(a, -1);
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < nums.length;i ++) {
            while (!stack.empty() && nums[stack.peek()] > nums[i]) {
                a[stack.peek()] = i-stack.peek();
                stack.pop();
            }
            stack.push(i);
        }
        long r = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == -1) {
                a[i] = a.length - i;
            }
            r += a[i];
        }
        return (int) r;
    }
}

//    vector<int> NextLarger(vector<int> &data) {
//        vector<int> output(data.size(), -1); //首先都初始化为-1
//        stack<int> monoStack;
//
//        for (int i=0; i<data.size(); ++i) {
//            while(!monoStack.empty() && data[monoStack.top()]<data[i]) {
//                output[monoStack.top()] = i-monoStack.top();
//                monoStack.pop();
//            }
//            monoStack.push(i);
//        }
//
//        return output;
//    }
