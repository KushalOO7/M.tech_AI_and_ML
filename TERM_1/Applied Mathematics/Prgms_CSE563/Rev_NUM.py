def revDig(n):
    st=str(n)
 
    st=list(st)
    str.reverse(st)
    
    st=''.join(st)
    n=int(st)
    return n

n = input()
print("Reverse of given input number is ", revDig(n))