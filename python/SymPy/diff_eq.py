# -*- coding: utf-8 -*-
from sympy import *

def main():

    var(['i','t','R','C'])

    # solve equation
    ans = dsolve(i(t).diff(t) + i(t)/(C*R), i(t), hint='best')
    # display the results
    print(ans)

if __name__ == '__main__':
    main()
