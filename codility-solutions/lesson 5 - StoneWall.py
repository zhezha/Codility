# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(H):
    # write your code in Python 2.7
    N = len(H)
    if N == 1:
        return 1;
    
    count = 1
    stack = [H[0]]
    for i in xrange(1, N):
        # For each H[i], remove all elements larger than H[i] in stack
        while stack and stack[len(stack) - 1] > H[i]:
            stack.pop()
        if stack and stack[len(stack) - 1] == H[i]:
            pass
        else:
            count += 1
            stack.append(H[i])
    return count