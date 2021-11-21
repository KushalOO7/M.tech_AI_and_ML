''' USING IN-BUILT FUNCTION (Including Sign-bit)'''

def fnc(n):
    
    if(n==0):
        return 0
    if(n>0):
        return bin(n).replace("0b", "0")
        # "{0:b}".format(int(n))
    else:
        return bin(n).replace("-0b", "1")

def fnc2(m):
        return int(m,2)

n = int(input("enter the decimal value :"))
m = input("enter the binary value :")

print("binary value of ",n," is : ",fnc(n))
print("decimal value of ",m," is : ",fnc2(m))


''' WITHOUT USING IN-BUILT FUNCTION (Binary of |DEC|) '''

'''
def fnc3(p):
        
    if(p==0):
        return 0
    
    if (p>0):
        fnc3(p//2)
        print(p%2,end=' ')
        
    if(p<0):
        temp=str(p)
        s=temp[1:]
        s=''.join(s)
        p=int(s)
        fnc3(p)

p = int(input("enter decimal value :"))
fnc3(p)
'''