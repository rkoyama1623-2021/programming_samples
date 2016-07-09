#!/usr/bin/env python
from __future__ import print_function
import argparse
import time

import numpy as np
import six

import chainer
from chainer import computational_graph
from chainer import Function, gradient_check, Variable, optimizers, serializers, utils
from chainer import Link, Chain, ChainList
import chainer.links as L
import chainer.functions as F
from chainer import optimizers
from chainer import serializers

import matplotlib.pyplot as plt

class xyFunc(chainer.Chain):
    def __init__(self, n_in, n_units, n_out):
        super(xyFunc, self).__init__(
            l1=L.Linear(n_in, n_units),
            l2=L.Linear(n_units, n_out)
        )
    def __call__(self, x):
        h1 = F.relu(self.l1(x))
        h2=2*F.tanh(self.l2(h1))
        return h2

if __name__=='__main__':
    # plot setup
    fig, ax = plt.subplots()
    ax.set_ylim(-1.3, 1.3)
    fig.show()
    # We need to draw the canvas before we start animating...
    fig.canvas.draw()
    background = fig.canvas.copy_from_bbox(ax.bbox)

    # generate network
    model=xyFunc(2,400,1)
    n_epoch = 200
    dx=0.001

    # training data
    xOrig=np.arange(0,2*np.pi,dx,dtype=np.float32)
    yOrig=np.sin(xOrig)
    N_all=len(xOrig)
    N=int(np.floor(2.0/3.0*N_all))
    N_test=N_all-N
    batchsize = int(np.floor(N/10.0))

    idx=np.random.permutation(range(N_all))
    xOrig2=xOrig[idx]
    yOrig2=yOrig[idx]
    xTmp=np.array([xOrig2],dtype=np.float32)
    oneTmp=np.array([np.ones(N_all)],dtype=np.float32)

    xData=np.c_[xTmp.T,oneTmp.T]
    yData=np.array([yOrig2]).T

    x_train,x_test=np.split(xData,[N])
    y_train,y_test=np.split(yData,[N])

    # Setup optimizer
    optimizer = optimizers.Adam()
    optimizer.setup(model)

    # Learning loop
    for epoch in six.moves.range(1, n_epoch + 1):
        print('epoch', epoch)
        # training
        sum_loss = 0.0
        perm = np.random.permutation(N)
        for i in six.moves.range(0, N, batchsize):
            x = chainer.Variable(np.asarray(x_train[perm[i:i + batchsize]]))
            t = chainer.Variable(np.asarray(y_train[perm[i:i + batchsize]]))
            model.zerograds()
            y = model(x)
            loss = F.mean_squared_error(y, t)
            sum_loss += loss.data
            loss.backward()
            optimizer.update()
        print('train mean loss={}'.format(sum_loss / N))

        # test
        x = chainer.Variable(np.asarray(x_test))
        t = chainer.Variable(np.asarray(y_test))
        y = model(x)
        loss = F.mean_squared_error(y, t)
        print('   test mean loss={}'.format(loss.data / N_test))


        xOrigTest=np.arange(0,2*np.pi,0.1,dtype=np.float32)
        yOrigTest=np.sin(xOrigTest)
        n=len(xOrigTest)
        xTmp=np.array([xOrigTest],dtype=np.float32)
        oneTmp=np.array([np.ones(n)],dtype=np.float32)
        xData=np.c_[xTmp.T,oneTmp.T]
        yData=np.array([yOrigTest]).T
        xTest = chainer.Variable(np.asarray(xData))
        yTest = model(xTest)
        line=ax.plot(xTest.data[:,0], yTest.data[:,0], 'r', linewidth=2,animated=True)[0]
        line2=ax.plot(xOrigTest,yOrigTest,'b',linestyle="--")[0]

        fig.canvas.restore_region(background)
        if epoch==1:
            line.set_ydata(yTest.data[:,0])
        ax.draw_artist(line)
        ax.draw_artist(line2)
        fig.canvas.blit(ax.bbox)





