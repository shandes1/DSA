import time
import random
def QuickSort(A,lb,ub):
    if (lb<ub):
        p=partition(A,lb,ub)
        QuickSort(A,lb,p-1)
        QuickSort(A,p+1,ub)

def partition(A,lb,ub):
    start=lb;
    end=ub;
    Pivot=A[lb]

    while start<end:
        while start<=ub and A[start]<=Pivot:
            start +=1
        while end>=lb and A[end]>Pivot: 
            end -=1
 
        if(start<end):
            A[start],A[end]=A[end],A[start]
    
    A[lb],A[end]=A[end],A[lb]
    return end
   
n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
QuickSort(a,0,len(a)-1)
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a)            