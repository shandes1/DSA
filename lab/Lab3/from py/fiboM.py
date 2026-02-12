table={}
#if we use list instead of dic we use table=[0]*100

def FiboM(n):
    if n==1 or n==2:
        return 1
    else:
        if n not in table:
            table[n]=FiboM(n-1)+FiboM(n-2)
        return table[n]

print(FiboM(6))