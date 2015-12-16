# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"


def solution(A):
    # write your code in Python 2.7
    N = len(A)
    if N == 0:
        return -1
    elif N == 1:
        return 0
    
    size = 0
    for i in xrange(N):
        if size == 0:
            size += 1
            value = A[i]
        else:
            if value != A[i]:
                size -= 1
            else:
                size += 1
    if size == 0:
        return -1
    candidate = value
    count = 0
    for i in xrange(N):
        if A[i] == candidate:
            count += 1
            if count > N // 2:
                return i
    return -1