package com.netease.music.codeforces.round551.div2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Created by dezhonger on 2019/4/14
 */
public class D {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        private int n;
        private int[] m;
        private int[] pa;
        private List<Integer>[] nodes;
        //dp[i]表示该结点可以取到的最大值，1表示最大值，2次大值
        private int[] dp;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = new int[n + 1];
            pa = new int[n + 1];
            dp = new int[n + 1];
            for (int i = 1; i <= n; i++) m[i] = in.nextInt();
            nodes = new List[n + 1];
            for (int i = 1; i <= n; i++) nodes[i] = new ArrayList<>();
            for (int i = 2; i <= n; i++) {
                pa[i] = in.nextInt();
                nodes[pa[i]].add(i);
            }
            int leafNumber = 0;
            for (int i = 1; i <= n; i++) {
                if (nodes[i].size() == 0) leafNumber++;
            }
            dfs(1);
            System.out.println(leafNumber + 1 - dp[1]);
        }

        private void dfs(int nodeNumber) {
            //叶子节点
            if (nodes[nodeNumber].size() == 0) {
                //1表示最大值
                dp[nodeNumber] = 1;
                return;
            }


            //1:max  0:min

            for (int v : nodes[nodeNumber]) {
                dfs(v);
            }

            if (m[nodeNumber] == 1) {
                dp[nodeNumber] = Integer.MAX_VALUE;
                for (int v : nodes[nodeNumber]) {
                    //小的表示最大值
                    dp[nodeNumber] = Math.min(dp[nodeNumber], dp[v]);
                }
            } else {
                dp[nodeNumber] = 0;
                for (int v : nodes[nodeNumber]) {
                    dp[nodeNumber] += dp[v];
                }
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
