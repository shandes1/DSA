def multiple(n,a):
    if n<1:
        return a
    else:
        return multiple(n-1,a*a)
x=multiple(3,5)
print(x)