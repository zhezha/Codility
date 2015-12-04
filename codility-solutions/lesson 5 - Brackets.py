# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(S):
    # write your code in Python 2.7
    N = len(S)
    if N % 2 == 1:
        return 0
    
    seq = map(S)
    stack = []
    sum = 0
    for i in xrange(N):
        if seq[i] > 0:
            stack.append(seq[i])
            sum += seq[i]
        elif seq[i] < 0:
            if not stack or (stack[len(stack) - 1] + seq[i]) != 0:
                return 0
            else:
                stack.pop()
                sum += seq[i]
    if sum == 0:
        return 1
    else:
        return 0
            
            
def map(S):
    N = len(S)
    mapping = {'(':1, ')':-1, '[':2, ']':-2, '{':3, '}':-3}
    result = []
    for i in xrange(N):
        result.append(mapping[S[i]])
    return result