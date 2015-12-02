# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(S, P, Q):
    # write your code in Python 2.7
    N = len(S)
    M = len(P)
    mapping = {'A':1, 'C':2, 'G':3, 'T':4}
    result = []
    if (N == 1):
        result.append(mapping[S[0]])
        return result 
    
    seq_factor = map_factor(S, mapping)
    pref = prefix_sums(seq_factor);
    for i in xrange(0, M):
        slice = count_slice(pref, P[i], Q[i])
        for j in xrange(0, 4):
            if (slice[j] > 0):
                result.append(j + 1);
                break;
    return result


def count_slice(P, x, y):
    result = [0] * 4;
    for i in xrange(0, 4):
        result[i] = P[i][y + 1] - P[i][x]
    return result
    
    
def prefix_sums(A):
    N = len(A[0])
    P = []
    for i in xrange(0, 4):
        P.append([0] * (N + 1))
    for i in xrange(0, 4):
        for j in xrange(1, N + 1):
            P[i][j] = P[i][j - 1] + A[i][j - 1]
    return P;
    
    
    
def map_factor(S, mapping):
    N = len(S)
    F = []
    for i in xrange(0, 4):
        F.append([0] * N)
    for i in xrange(0, N):
        F[mapping[S[i]] - 1][i] = 1
    return F