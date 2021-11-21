''' f = open('file124.txt','w')

f.write("my name is kushal")

f.close()


f1 = open('file124.txt','r')

print(f1.read(10))

f1.close()



f2 = open('file124.txt','a')

f2.write("\nmy name is kushal dath")

f2.close()
'''

f3 = open('file124.txt','r')

for line in f3:
    print(line)

f3.close()
