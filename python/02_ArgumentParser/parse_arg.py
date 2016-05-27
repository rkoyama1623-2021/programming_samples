#!/usr/bin/env python
import argparse
import sys

parser = argparse.ArgumentParser(description='example:./parse_arg.py aaa -s fuga')
# setting for first argument
parser.add_argument('first_arg', \
                    action='store', \
                    nargs=None, \
                    const=None, \
                    default=None, \
                    type=str, \
                    choices=['aaa','bbb'], \
                    help='first arg (necesarry)', \
                    metavar=None)
# setting for second argument
parser.add_argument('-s', '--second-arg', \
                    action='store', \
                    nargs='?', \
                    const=None, \
                    default=None, \
                    type=str, \
                    choices=None, \
                    help='second arg (optional) give by -s or --secondary', \
                    metavar=None)
parser.add_argument('-t', '--third-arg', \
                    action='store', \
                    nargs='+', \
                    const=None, \
                    default=['aaa'], \
                    type=str, \
                    choices=['aaa','bbb'], \
                    help='Extentions of file which you want to sort. (default: jpg)', \
                    metavar=None)


args = parser.parse_args()

#args = parser.parse_args(sys.argv[1:])

print "fitst_arg:",args.first_arg
print "--second-arg:", args.second_arg
