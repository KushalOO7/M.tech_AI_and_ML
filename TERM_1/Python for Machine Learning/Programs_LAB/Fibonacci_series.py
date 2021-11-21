def fib(n):
   if (n<=1):
       return n
   else:
       return(fib(n-1)+fib(n-2))
  
k = int(input("enter the number to generate fibo. ser. :"))
  
if (k<=0):
   print("Plese enter a positive integer")
else:
   print("fibonacci series :")  
   for i in range(k): 
       print(fib(i),end=' ')