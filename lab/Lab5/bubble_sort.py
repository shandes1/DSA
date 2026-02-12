import time
import random
def BubbleSort(A,n):
    for i in range(n):
        for j in range(n-i-1):
            if A[j]>A[j+1]:
                A[j],A[j+1]=A[j+1],A[j]



            
n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
BubbleSort(a,len(a))
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a)