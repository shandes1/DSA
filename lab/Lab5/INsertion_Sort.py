import time
import random
def InsertionSort(A,n):
    for i in range(n):
        temp=A[i]
        j=i-1

        while j>=0 and temp<A[j]:
            A[j+1]=A[j]
            j-=1

        A[j+1]=temp;

n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
InsertionSort(a,len(a))
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a)            
