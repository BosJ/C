from ctypes import *
myso = CDLL("/opt/scripts/q/myso.so", mode = RTLD_GLOBAL)
myso2 = CDLL("/opt/scripts/q/myso2.so", mode = RTLD_GLOBAL)

myso2.use_sem_init()
