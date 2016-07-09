import numpy as np
import chainer
from chainer import cuda, Function, gradient_check, Variable, optimizers, serializers, utils
from chainer import Link, Chain, ChainList
import chainer.functions as F
import chainer.links as L

from __future__ import print_function

x_data = np.array([5], dtype=np.float32)
x = Variable(x_data) #x.data=5,x.grad=None
print ("x.data={0}".format(x.data)) # dy/dx=8

y = x**2 - 2 * x + 1 #y.data=16
print ("y.data={0}".format(y.data)) # dy/dx=8

y.backward() #x.grad=8 (differential of y when x=5)
print ("x.grad={0}".format(x.grad))


z=2*x
y=x**2-z+1
y.backward(retain_grad=True)
print ("x.grad={0}".format(x.grad)) # dy/dx=8
print ("z.grad={0}".format(z.grad)) # dy/dz=-1



x = Variable(np.array([[1, 2, 3], [4, 5, 6]], dtype=np.float32))
y = x**2 - 2*x + 1
y.grad = np.ones((2, 3), dtype=np.float32) # initial error
y.backward()
x.grad


# dy/dx =2*x-2
