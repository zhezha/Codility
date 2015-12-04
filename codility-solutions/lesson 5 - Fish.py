# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(A, B):
    # write your code in Python 2.7
    N = len(A)
    if N == 1:
        return 1
    
    # stack for downstream fish
    stack = []
    count = 0
    for i in xrange(N):
        if B[i] == 1:
            stack.append(A[i])
        else:
            while stack and stack[len(stack) - 1] < A[i]:
                stack.pop()
            if stack:
                pass
            else:
                count += 1
    return count + len(stack)