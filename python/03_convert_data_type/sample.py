#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys
import struct

def main():
    infile = open('test.bin', 'r')
    dataFormat=['i','d','c']
    dataNumber=[1,1,3]
    for df,dn in zip(dataFormat,dataNumber):
        data = infile.read(struct.calcsize(df)*dn)
        data2=struct.unpack(df*dn,data)
        print data2

if __name__ == '__main__':
    main()

