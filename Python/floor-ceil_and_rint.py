import numpy
numpy.set_printoptions(legacy='1.13')

np_ar = numpy.array(list(map(float,input().split())),float)
print(numpy.floor(np_ar))
print(numpy.ceil(np_ar))
print(numpy.rint(np_ar))