def flatten(x): # Flattens a list,set,tuple,dict...
    flattened_items = []
    for i in x:
        flattened_items.extend(x[i])
    return flattened_items

def compare(a,b): # Function for checking if 2 minterms differ by 1 bit only
    c = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            mismatch_index = i
            c += 1
            if c>1:
                return (False,None)
    return (True,mismatch_index)

while True:
    minterms = [int(i) for i in input("Enter the minterms: ").strip().split()]
    minterms.sort()
    size = len(bin(minterms[-1]))-2# 3-variable(3-bit) for the zfill function
    if(size==3):
        break
    else:
        print("enter the valid three bit Decimal number in minterms")
    
groups = {}
all_pi = set()

for minterm in minterms:
    try:
        groups[bin(minterm).count('1')].append(bin(minterm)[2:].zfill(size))
    except KeyError:
        groups[bin(minterm).count('1')] = [bin(minterm)[2:].zfill(size)]


print("\n\nGroup  \tMinterms\tBinary(Minterms)\n%s"%('_'*40))

for i in sorted(groups.keys()):
    print(i,":")           # Printing group number in the table
    for j in groups[i]:
        print("\t\t    %-15d%s"%(int(j,2),j)) # Print minterm and its binary form
    print('_'*40)
    
while True:
    # Initializing the essential parameters
    temp = groups.copy()
    groups = {}
    m = 0
    marked = set()
    should_stop = True
    l = sorted(list(temp.keys()))
    
    for i in range(len(l)-1):
        for j in temp[l[i]]:        # Loop which iterates through current group elements
            for k in temp[l[i+1]]:  # Loop which iterates through next group elements
                res = compare(j,k) # Compare the minterms
                
                if res[0]:         # If the minterms differ by 1 bit only
                    try:
                        if (j[:res[1]]+'-'+j[res[1]+1:]) not in groups[m]:
                            groups[m].append(j[:res[1]]+'-'+j[res[1]+1:]) # Put '-' in the changing bit and add it to corresponding group
                        else: None

                    except KeyError:
                        groups[m] = [j[:res[1]]+'-'+j[res[1]+1:]]
                        # If the group doesn't exist, create the group at first and then put a '-' in the changing bit and add it to the newly created group
                        
                    should_stop = False
                    marked.add(j) # Mark element j
                    marked.add(k) # Mark element k
        m+=1
        
    unmarked = set(flatten(temp)).difference(marked) # Unmarked elements of each table
    
    all_pi = all_pi.union(unmarked)                 # Adding Prime Implicants to global list
    
    print("Prime Implicants of the table : ")
    if len(unmarked)==0:
        None
    else:
        print(', '.join(unmarked)) # Printing Prime Implicants of current table

    if should_stop: # If the minterms cannot be combined further
        print("\n\nFinal Expression: ")
        if len(all_pi)==0:
            None
        else:
            print('+ '.join(all_pi)) # Print all prime implicants
        break

