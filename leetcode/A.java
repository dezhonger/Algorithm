package com.netease.music.leetcode.contest.gaoxiaobei;

/**
 * Created by dezhonger on 2019/4/21
 */
public class A {
    public static void main(String[] args) {
        System.out.println(new A().missingElement(new int[]{4, 7, 9, 10}, 1));
        System.out.println(new A().missingElement(new int[]{4, 7, 9, 10}, 3));
        System.out.println(new A().missingElement(new int[]{1, 2, 4}, 3));
    }
    public int missingElement(int[] nums, int k) {
        int cnt = 0;
        int start = nums[0];
        int result = 0;
        for (int i = 1; i < nums.length; i++) {
            int dif = nums[i] - nums[i - 1] - 1;
            if (dif >= k) {
                result = nums[i - 1] + k;
                break;
            } else {
                k -= dif;
            }
        }
        if (result != 0) {
            return result;
        } else {
            return nums[nums.length - 1] + k;
        }
    }
}
