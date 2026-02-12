# def power(a,n):
#     if n==0:
#         return 1
#     else:
#         return a*power(a,n-1)

# print(power(5,3)) 


def tailpower(a,n,temp=1):
    
    if n==0:
        return temp
    else:
        return tailpower(a,n-1,temp*a)


print(tailpower(5,3))