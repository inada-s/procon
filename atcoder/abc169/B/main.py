input()
A = list(map(int, input().split()))
ans = 1

if 0 in A:
    print(0)
    exit()

for a in A:
    ans *= a
    if 1000000000000000000 < ans:
        print(-1)
        exit()

print(ans)
