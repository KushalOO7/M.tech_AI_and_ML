# Fibonacci using Normal Recursion
def fib_Normal(m):
    if m<=1:
        return m
    else:
        return fib_Normal(m-2)+fib_Normal(m-1)

m=int(input("enter the number to generate fibo. ser. for Normal Rec.:"))

if m<=0:
   print("Plese enter a positive integer")
else:
   print("fibonacci series :")  
   for i in range(m): 
       print(fib_Normal(i),end=' ')

print("\n\n")

#####################################################

# Fibonacci using Tail Recursion
def fib_Tail(n,bef,nxt):
    if n==0:
        return bef
    if n==1:
        return nxt
    else:
        return fib_Tail(n-1,nxt,bef+nxt)

n=int(input("enter the number to generate fibo. ser. for Tail Rec.:"))

if n<=0:
   print("Plese enter a positive integer")
else:
   print("fibonacci series :")  
   for i in range(n): 
       print(fib_Tail(i,0,1),end=' ')



       
