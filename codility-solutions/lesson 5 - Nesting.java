// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(String S) {
        // write your code in Java SE 8
        int N = S.length();
        if (N % 2 == 1)
            return 0;
        
        int count1 = 0;
        int count2 = 0;
        
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (c == '(')
                count1++;
            else if (c == ')')
                count2++;
            
            if (count1 < count2)
                return 0;
        }
        
        if (count1 == count2)
            return 1;
        else
            return 0;
    }
}