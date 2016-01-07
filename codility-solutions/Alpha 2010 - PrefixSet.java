// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        int len = A.length;
        if (len == 1)
            return 0;
        
        int[] count = new int[len];
        for (int i = 0; i < len; i++) {
            count[A[i]]++;
        }
        int totalNum = 0;
        for (int i = 0; i < len; i++) {
            if (count[i] > 0)
                totalNum++;
        }
        for (int i = 0; i < len; i++)
            count[i] = 0;
        int result = 0;
        for (int i = 0; i < len; i++) {
            if (count[A[i]] == 0) {
                totalNum--;
                if (totalNum == 0) {
                    result = i;
                    break;
                }
                count[A[i]]++;
            }
        }
        return result;
    }
}