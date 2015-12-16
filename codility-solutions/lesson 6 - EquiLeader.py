# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    # write your code in Python 2.7
    N = len(A)
    if N == 1:
        return 0
    elif N == 2:
        return 1 if (A[0] == A[1]) else 0
    
	# Equi leader must also be global leader
	# Therefore find the global leader first
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
        return 0
    candidate = value
    # Calculate the prefix_sum of occurrence for global leader
    prefix_sum = [0] * (N + 1)
    for i in xrange(0, N):
        if candidate == A[i]:
            prefix_sum[i + 1] = prefix_sum[i] + 1
        else:
            prefix_sum[i + 1] = prefix_sum[i]
	# If no global leader, return 0
    if prefix_sum[N] <= N // 2:
        return 0
    # Check equi leaders
    count = 0
    for i in xrange(0, N - 1):
        if prefix_sum[i + 1] > (i + 1) // 2 and (prefix_sum[N] - prefix_sum[i + 1]) > (N - i - 1) // 2:
            count += 1
    return count