#!/usr/bin/env python
#-*- encoding:utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import copy
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

def func0(x,y):
    return (np.ones(np.shape(x))/(1+(x**2+y**2)))*np.cos(x*2+y**2)
def func1(x,y):
    return (np.ones(np.shape(x))/(4+(x**2+y**2)))*(np.sin(x)+ np.sin(y))
def test_plot():
    # make mesh
    x = np.arange(-12, 12, 0.4)
    y = np.arange(-12, 12, 0.4)
    X, Y = np.meshgrid(x, y)
    Z = func1(X,Y)

    # plot
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm)
    plt.show()

# ret=nelder_mead([0,0],lambda x: func0(x[0],x[1]))
# ret=nelder_mead([5,5],lambda x: np.linalg.norm(x))
def nelder_mead (_x0,func,debug=True):
    x0=np.array(_x0)
    dim=len(x0)
    dd=10
    calcMax=50

    alpha=1
    gamma=2
    rho=-0.5
    sigma=0.5

    x=[x0]
    deltaX=np.eye(dim)
    otherVertices=x0+dd*deltaX
    for i in range(dim):
        x.append(otherVertices[i])
    for count in range(calcMax):
        x=sorted(x,key=func)
        plotVertices(x)
        com=np.sum(x,0)/len(x)
        xr=x[0]+alpha*(x[0]-x[-1])

        fx0=func(x[0])
        fxr=func(xr)
        fxn=func(x[-1])
        if fx0<=fxr and fxr<=fxn:
            # 反射
            if debug:
                print "reflect"
            x[-1]=xr.copy()
        elif fxr < fx0:
            # 膨張
            if debug:
                print "inflate"
            xe=x0+gamma*(x[0]-x[-1])
            if func(xe) < fxr:
                x[-1]=xe.copy()
            else:
                x[-1]=xr.copy()
        else:
            if debug:
                print "hoge"
            xc=x[0]+rho*(x[0]-x[-1])
            if func(xc) < fxn:
                x[-1]=xc.copy()
            else:
                tmp=[x[0]+sigma*(x[i]-x[0]) for i in range(0,dim+1)]
                x=tmp

        plotVertices(x)

    com=np.sum(x,0)/len(x)
    plt.show()
    return com


# vertices=np.array([x0,y0],[x1,y1],...)
def plotVertices(_vertices):
    tmp=copy.deepcopy(_vertices)
    tmp.append(tmp[0])
    vertices=np.array(tmp)
    x=vertices.T[0]
    y=vertices.T[1]
    plt.plot(x,y,"-")

if __name__=="__main__":
    ret=nelder_mead([5,5],lambda x: np.linalg.norm(x))
    print "the function f(x_vec) is minimum when x_vec is ",ret
