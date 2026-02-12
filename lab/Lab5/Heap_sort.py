import time
import random
def HeapSort(A,n):
    Build_Max_Heap(A,n)
    
    for i in range(n,1,-1):
        A[i], A[1]=A[1], A[i]
        Max_Heapify(A,1,i-1)

def Build_Max_Heap(A,n):
    for i in range(n//2,0,-1):
        Max_Heapify(A,i,n)


def Max_Heapify(A,i,n):
    largest=i
    left=2*i
    right=2*i+1

    if left<=n and A[left]>A[largest]:
        largest=left
    if right<=n and A[right]>A[largest]:
        largest=right
    
    if largest!=i:
        A[i],A[largest]=A[largest],A[i]
        Max_Heapify(A,largest,n)


n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
HeapSort(a,len(a)-1)
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a[1:])  