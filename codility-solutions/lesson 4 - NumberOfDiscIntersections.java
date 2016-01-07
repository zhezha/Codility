// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        int result = 0;
        
        if (N < 2)
            return 0;
        
        long[] startPoint = new long[N];
        long[] endPoint = new long[N];
        for (int i = 0; i < N; i++) {
            startPoint[i] = (long) i - A[i];
            endPoint[i] = (long) i + A[i];
        }
        Arrays.sort(startPoint);
        Arrays.sort(endPoint);
        
        int[] sign = mergeArrays(startPoint, endPoint);
        
        int numStart = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            if (sign[i] == 0)
                numStart += 1;
            else if (sign[i] == 1) {
                numStart -= 1;
                result += numStart;
                if (result > 10000000)
                    return -1;
            }
        }  
        
        return result;
    }
    
    // The process is similar to count bracket pair.
	// The counting starts from the smallest startPoint,
	// when meet a start point, counter increment by 1,
	// when meet an end point, the counter decrement by 1 and out put an intermediate result.
	// For example, A[0] = 1, A[1] = 5, A[2] = 2, A[3] = 1, A[4] = 4, A[5] = 0,
	// the sequence of start point and end point is:
	// s(-4), s(-1), s(0), s(0), e(1);   s(2), e(4);   e(4);   s(5), e(5);   e(6);   e(8).
	// The result is 3(= 1 + 1 + 1 + 1 - 1) + 3(= 3 + 1 - 1) + 2(= 3 - 1) + 2(= 2 + 1 - 1) + 1(= 2 - 1) + 0(=1 - 1)
    int[] mergeArrays(long[] A, long[] B) {
        int N = A.length;
        int[] sign = new int[2 * N];
        
        int pts = 0;
        int pte = 0;
        for (int i = 0; i < 2 * N; i++) {
            if (pts < N && pte < N){
                if (A[pts] <= B[pte]) {
                    sign[i] = 0;
                    pts++;
                }
                else {
                   sign[i] = 1;
                   pte++;
                }
            }
            else if (pts < N) {
                sign[i] = 0;
                pts++;
            }
            else {
                sign[i] = 1;
                pte++;
            }
        }
        
        return sign;
    }
    
    
    void print(long[] A) {
        for (int i = 0; i < A.length; i++) {
            System.out.print(A[i] + ", ");
        }
        System.out.println();
    }
}