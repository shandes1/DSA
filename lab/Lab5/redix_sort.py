import time 
import random

def redixSort(A):
   max_value=max(A)
   length=len(str(max_value))

   divisor=1
   for _ in range(length):
        buckets=[[]for _ in range(10)]
        for val in A:
            digit=(val//divisor)%10
            buckets[digit].append(val)
        
        A.clear()
        for bucket in buckets:
            A.extend(bucket)
        
        divisor *=10
    


n= int(input("Enter the no of element:"))
a=[random.randint(0,1000) for _ in range(n)]
t1=time.time()
redixSort(a)
print(f"The time taken for the swap is {time.time()-t1} sec")
print(a)    