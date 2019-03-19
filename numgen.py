import random

def permutation(lst):

    if len(lst) == 0:
        return []

    if len(lst) == 1:
        return [lst]


    l = []

    for i in range(len(lst)):
        m = lst[i]
        remLst = lst[:i] + lst[i+1:]
        for p in permutation(remLst):
            l.append([m] + p)
    return l

#data = []
#n = 20
#i = 0
#while i < n:
#   data.append(i)
#    i += 1

#for p in permutation(data):
#   print ' '.join(map(str, p))

list = random.sample(range(0, 5000), 500);
print ' '.join(map(str, list))
