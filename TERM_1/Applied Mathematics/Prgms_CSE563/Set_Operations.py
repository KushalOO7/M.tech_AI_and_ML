# Initializing the sets
A = {1,2,3,4,5,6,7,8,9}
B = {2,4,6,8,10,12,14}
C = {11,13,15,17}
D = {3,4,5,6}
E = {}

print("A = ",A,"\nB = ",B,"\nC = ",C,"\nD = ",D,"\nE = ",E,"\n")

# Set Operations
print("A union B :",A|B,"\n")  
# set1.union(set2,set3,...)

print("A intersection B :",A&B,"\n") 
# set1.intersection(set2,set3,...)

print("A difference B :",A-B,"\n") 
# set1.difference(set2)

print("A symmetrical difference B :",A^B,"\n")
# set1.symmetrical_difference(set2)
# only(A) uninon only(b) 

print("A and C are Disjoint :",A.isdisjoint(C),"\n")
# if Disjoint return true else false

print("D is subset to A :",D.issubset(A),"\n")
print("C is subset to A :",C.issubset(A),"\n")

print("A is superset to D :",A.issuperset(D),"\n")

print("Adding the element '7' to set D")
D.add(7)
print("Set D after adding element '7' :",D,"\n")

print("Clearing all elements in set D")
D.clear()
print("Set D after clearing the elements :",D,"\n")

print("Removing the element '12' from set B")
B.remove(12)
print("Set B after removing the element 12 :",B,"\n")

print("Copying the elements in set A to set E")
E = A.copy()
print("Set E after copying the Set A is :",E,"\n")

print("Poping an elemenet from set E")
E.pop()
print("Set E after poping the top element is :",E)
