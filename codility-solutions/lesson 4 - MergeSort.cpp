// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// reference: https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F
int min(int x, int y) {
    return (x < y) ? x : y;
}


vector<int> merge_sort(vector<int> &A) {
    int N = A.size();
    if (N == 0 || N == 1)
        return A;
    
	// copy A to a
    vector<int> a(A);
	// b is a temp vector for storing middle result
    vector<int> b(N);
    
	// first sort segment with length with 2, then 4, 8, 16, ...
    for (int seg = 1; seg < N; seg += seg) {
		// divide the segment into two parts: (start, start + seg) and (start + seg, start + 2*seg)
        for (int start = 0; start < N; start += 2*seg) {
            int low = start;
            int mid = min(start + seg, N);
            int high = min(start + 2*seg, N);
            
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            
			// sort and merge
            while (start1 < end1 && start2 < end2) {
                if (a[start1] < a[start2]) {
                    b[k] = a[start1];
                    start1++;
                }
                else {
                    b[k] = a[start2];
                    start2++;
                }
                k++;
            }
            
            while (start1 < end1) {
                b[k] = a[start1];
                start1++;
                k++;
            }
            
            while (start2 < end2) {
                b[k] = a[start2];
                start2++;
                k++;                
            }
        }
        
        a = b;
    }
    
    return a;
}


int solution(vector<int> &A) {
    // write your code in C++11
    int N = A.size();
    vector<int> sorted = merge_sort(A);
    
    int result1 = sorted[0] * sorted[1] * sorted[N-1];
    int result2 = sorted[N-3] * sorted[N-2] * sorted[N-1];
    
    return (result1 > result2) ? result1 : result2;
}