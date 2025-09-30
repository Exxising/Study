// 2023 04 19
// baekjoon 17425

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class b17425{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        int T = Integer.parseInt(bf.readLine());
        long[] sum = new long[1000002];

        for(int i=1; i<= 1000001; i++){
            for(int j=i; j<=1000001; j+=i){
                sum[j] += i;
            }
        }

        for(int i=2; i<=1000001; i++){
            sum[i] += sum[i-1];
        }

        for(int i=0; i<T; i++){
            int n = Integer.parseInt(bf.readLine());
            sb.append(sum[n]).append("\n");
        }
        System.out.println(sb);
    }
}