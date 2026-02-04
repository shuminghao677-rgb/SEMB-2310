def points():
    hash={}
    for i in range(1,7):
        for j in range(1,7):
            if (i+j) in hash:
                hash[i+j]+=1
            else:
                hash[i+j]=1
    return hash