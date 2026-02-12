import time
import random

def MergeSort(A,lb,ub):
    if (lb<ub):
        m=(lb+ub)//2
        MergeSort(A,lb,m)
        MergeSort(A,m+1,ub)
        merge(A,lb,m,ub)

def merge(A,lb,m,ub):
    i=lb;
    j=m+1;
    k=lb;
    B=[]

    # merge two sub
    while i<=m and j<=ub:
        if A[i] <A[j]:
            B.append(A[i])
            i +=1
        else:
            B.append(A[j])
            j +=1

    #copy remaining from left 
    while(i<=m):
        B.append(A[i])
        i +=1

    #copy remaining feom right
    while(j<=ub):
        B.append(A[j])
        j +=1
    
    #copy back to original
    for val in B:
        A[k]=val
        k +=1


n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
MergeSort(a,0,len(a)-1)
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a)            
