import numpy

def arrays(arr):
    np_ar = numpy.array(arr,float)
    return np_ar[::-1]

arr = input().strip().split(' ')
result = arrays(arr)
print(result)