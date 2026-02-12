def NaturalSum(n):
    if n==1:
        return 1
    else:
        return n+NaturalSum(n-1)

def TailSum(n,a):
    if n==1:
        return a
    else:
        return TailSum(n-1,n+a)
    

print(NaturalSum(4))
print(TailSum(4,1))
