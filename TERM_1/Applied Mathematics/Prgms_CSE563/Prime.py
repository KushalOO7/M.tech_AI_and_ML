from math import sqrt
n=int(input())
flag=0

if(n>1):
    for i in range(2, int(sqrt(n))+1):
        if (n%i==0):
            flag=1
            break
    if (flag==0):
        print("Given number is prime")
    else:
        print("Given number is not prime")
else:
    print("entered integer is not positive")