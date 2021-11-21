'''
flie = open('plt123.txt','w')
lines = ["hello"," Kushal"]
flie.writelines(lines)
flie.close()

print("Data has been recorded in file")
'''
'''
f = open('plt123.txt','r')
print(f.readline())
f.close()

f = open('plt123.txt','r')
print(f.readlines())
f.close()


f = open('plt123.txt','w')
while str !='@':
    str=input()
    if(str!='@'):
        f.write(str+'\n')
f.close()
'''

