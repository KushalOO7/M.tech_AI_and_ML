# using Tail Recursion
def isprime(n,i=2):
  if (n<=2):
    return True if(n==2) else False
  if (n%i==0):
    return False
  if (n<i*i):
    return True

  return isprime(n,i+1)

# using Normal recursion
def isprimes(n,d=None):
  if d is None:
    d=n-1
  while d>=2:
    if n%d==0:
      return False
    else:
      return isprimes(n,d-1)
  else:
    return True

# for normal recursion
def printprimes(p,q):
    while(p<=q):
        if(isprimes(p)):
            print(p,end=' ')
        p+=1

# for tail recursion
def printprime(p,q):
    while(p<=q):
        if(isprime(p)):
            print(p,end=' ')
        p+=1
    
m=int(input("enter the lower limit :"))
n=int(input("enter the upper limit :"))
if(m>n):
    print("invalid input!!")
else:
  print("For Tail Recursion :")
  printprime(m,n)
  print("\nFor Normal Recursion :")
  printprimes(m,n)
  
# TAIL REC FUNCTION
'''
def prime(i,n1,n2):
  if n1%i==0:
    print("Not Prime=", n1)
    return 1
  if i==int(n1/2):
    print("Prime=", n1)
    return 0
  prime((i+1),n1,n2)

def ran(j1,j2):
  prime(2,j1,j2)
  if j1==j2:
    return 0
  else:
    return ran(j1+1,j2)
  
def main():
  a=ran(10,50)
  
main()
'''
    
