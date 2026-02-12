import time
def Fact(n):
    if n==1:
        return 1
    else:
        return n*Fact(n-1)

def TailFact(n,a):
    if n==1:
        return a
    else:
        return TailFact(n-1,a*n)

start=time.time()
print(Fact(4))
print(time.time()-start)

tail=time.time()
print(TailFact(4,1))
print(time.time()-tail)
