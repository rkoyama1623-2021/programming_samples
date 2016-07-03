# -*- coding: utf-8 -*-
import sympy as syp
import sympy

# the best pretty printing
from sympy import init_printing
init_printing()

sympy.var("x:z") # set x,y,z as sympy.var
zc=sympy.Symbol('z_c')

def definFunc():
    f = x**2 + 3*x +y
    f_x2_y3=f.subs([(x,2),(y,3)])
    print ( "f(x,y)="+str(f) )
    print ("   f(2,3)=" + str(f_x2_y3) )

def irrationalFunc():
    f=sympy.cos(x)
    f_1=f.subs(x,1)
    f_1_float=f_1.evalf()
    print ( "f(x)="+str(f) )
    print ( "   f(1)="+str(f_1) )
    print ( "   f(1)="+str(f_1_float) )
    print ( "   f(1)="+str(sympy.N(f_1)) )

def differential():
    f=sympy.cos(x)
    print ( "f(x)="+str(f) )
    print ( "   f'(x)="+str(sympy.diff(f,x)) )
    print ( "   f'(x)="+str(f.diff(x)) )
def integrate():
    f=sympy.cos(x)
    print ( "f(x)="+str(f) )
    print ( "   \integrate f(x)="+str(f.integrate(x)) )
    print ( "   \integrate f(x)="+str(sympy.integrate(f,x)) )

def LaTex ():
    print ("export latex format")
    print ( "   " + str( sympy.latex(sympy.Integral(sympy.cos(x))) ) )



def beautifulEq():
    print "======================"
    print "please try:"
    print "  beautifulEq()"
    print "======================"
    f = x**2 + 3*x +2
    return sympy.Integral(f,x)

def main():
    definFunc()
    irrationalFunc()
    differential()
    integrate()
    LaTex()
    beautifulEq()

if __name__ == '__main__':
    main()

