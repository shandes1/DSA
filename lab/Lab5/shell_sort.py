import time
import random
def ShellSort(A,n):
    gap=n//2
    while gap>=1:
        for j in range(gap,n):
            i=j-gap
            while i >=0 and A[i]>A[i+gap]:
                A[i],A[i+gap]=A[i+gap],A[i]
                i=i-gap  #to look behind
        gap=gap//2


n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
ShellSort(a,len(a))
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a)                 

