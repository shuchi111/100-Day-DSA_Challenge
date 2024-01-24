#Chocolate Distribution
"""
Sample Input
3
5 3
1 2 3 4 5
5 4
1 2 3 4 5
5 8
1 2 3 4 5



Sample Output
5
3
0

"""
#solution
def solution (N, C):
    res = []
    s = []
    for i in range(N):
        if C[i] > 0:
            s.append(C[i])
        if C[i] == 0:
            p = s.pop()
            res.append(p)
    return res
    pass

N = int(input())
C = list(map(int, input().split()))

out_ = solution(N, C)
print (' '.join(map(str, out_)))

