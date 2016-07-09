import numpy as np
import chainer
from chainer import cuda, Function, gradient_check, Variable, optimizers, serializers, utils
from chainer import Link, Chain, ChainList
import chainer.functions as F
import chainer.links as L

from __future__ import print_function


f = L.Linear(3, 2)
f.W.data # initialized randomly

x = Variable(np.array([[1, 2, 3], [4, 5, 6]], dtype=np.float32))
y=f(x)
y.data

f.zerograds()

y.grad = np.ones((2, 2), dtype=np.float32)
y.backward()
f.W.grad
f.b.grad
x.grad


