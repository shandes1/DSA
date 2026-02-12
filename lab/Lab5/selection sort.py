import time
import random
def SelectionSort(A,n):
    for i in range(n):
        minimum=A[i]
        pos =i

        for j in range(i+1,n):
            if minimum>A[j]:
                minimum=A[j]
                pos=j
    
        if pos!=i:
            A[i],A[pos]=A[pos],A[i]


n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
SelectionSort(a,len(a))
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a)