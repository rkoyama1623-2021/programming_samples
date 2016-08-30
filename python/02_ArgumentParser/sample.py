#!/usr/bin/env python
# -*-coding:utf-8-*-
import argparse

p = argparse.ArgumentParser(description='Process some args.')

p.add_argument('f', type=str, help='input file', metavar='FILE')
p.add_argument('-d', type=str, help='directory name', metavar='DIRECTORY',required=True)
p.add_argument('-I', metavar='image', nargs=2, help='two image is needed')
p.add_argument("-n", const=9, nargs="?", help='set number (default 9)')
p.add_argument("-i", action='store_true', help='interactive flag')

try:
    import argcomplete
    argcomplete.autocomplete(p)
except:
    print "if argcomplete is installed, you can use tab completion"


args = p.parse_args()
print(args)
