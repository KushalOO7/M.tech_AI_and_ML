m = int(input("enter the lower range :"))
n = int(input("enter the upper range :"))
  
for i in range(m, n+1):
  if i>1:
    for j in range(2,i):
        if(i%j==0):
            break
    else:
        print(i)