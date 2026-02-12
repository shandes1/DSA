def bubble_sort(arr,n):
    for i in range(n):
        for j in range( n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]



def insertion_sort(A,n):
    for i in range(n):
        temp=A[i]
        j=i-1

        while j>=0 and temp<A[j]:
            A[j+1]=A[j]
            j-=1

        A[j+1]=temp;





data = [-1.5,7,3.5,-2,37,13.1,22.9]
# bubble_sort(data,len(data))
insertion_sort(data,len(data))
print( data)
