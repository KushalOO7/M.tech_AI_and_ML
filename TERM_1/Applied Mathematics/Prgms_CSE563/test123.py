'''
def flatten(x): # Flattens a list
    flattened_items = []
    for i in x:
        flattened_items.extend(x[i])
    print(set((flattened_items)))


grp = {1:['000'], 2:['001','100'] , 3:['111']}
flatten(grp)
'''

