#! /bin/usr/env python
#  -*- coding: utf-8 -*-

# check elapsed time
import re
import time
def elapsedTime(func):
    """
    デバッグ用デコレータ
    実効時間を表示するデコレータ
    """
    import functools
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        ellapes_time=end-start
        funcNameWC = re.search(r'at .*>', str(func))
        funcName=funcNameWC.string.replace(funcNameWC.group(),"").replace("<function ","")
        print "[",ellapes_time,"sec ]",funcName
        return result
    return wrapper
"""
when you don't want to check elapsed time, you can comment out following function.
"""
# def elapsedTime(func):
#     """
#     Do nothing
#     """
#     import functools
#     @functools.wraps(func)
#     def wrapper(*args, **kwargs):
#         return func(*args, **kwargs)
#     return wrapper

@elapsedTime
def sampleCode():
    hoge=[]
    for i in range(10**7):
        hoge.append(1)
    return hoge


print "you can check how long your function took time by adding elapsedTime decorator"
print "start sampleCode()"
sampleCode()
print "done"
