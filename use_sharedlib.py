from ctypes import *

sharedlib = CDLL("sharedlib/sharedlib.so")

print( sharedlib.add(1,2) )
