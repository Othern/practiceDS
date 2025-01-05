data = [10,12,18,1,3,5,9,26,32,41,7]

def merge(data1:list, data2:list):
    l = 0
    r = 0
    result = []
    while(l < len(data1) and r < len(data2)):
        if data1[l] <= data2[r]:
            result.append(data1[l])
            l+=1
        else:
            result.append(data2[r])
            r+=1
    if(l < len(data1)):
        result += data1[l:]
    if(r < len(data2)):
        result += data2[r:]
    return result
        

def MergeSort(data:list):
    if len(data) == 1:
        return data
    l = MergeSort(data[:int(len(data)/2)])
    r = MergeSort(data[int(len(data)/2) :])
    return merge(l,r)

print(MergeSort(data))