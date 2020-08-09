A, B = input().split(" ")
A = int(A.strip())
B = int(B.strip().replace(".", ""))
print(A * B // 100)