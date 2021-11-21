'''list_input = [True, False, False, True, False]'''

list_input = []
n = int(input("Enter number of elements : "))

for i in range(n):
    e = int(input())
    list_input.append(e) # adding the element to list

print("The given list is : "+str(list_input))

# AND Operation Using all()
ListAnd = all(list_input)

# OR Operation Using any()
ListOr = any(list_input)

print("List after performing AND among elements : "+str(ListAnd))
print("List after performing OR among elements : "+str(ListOr))

     

