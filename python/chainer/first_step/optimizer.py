import numpy as np
import chainer
from chainer import cuda, Function, gradient_check, Variable, optimizers, serializers, utils
from chainer import Link, Chain, ChainList
import chainer.functions as F
import chainer.links as L

from __future__ import print_function

# make network
class MyChain(Chain):
    def __init__(self):
        super(MyChain, self).__init__(
            l1=L.Linear(4, 3),
            l2=L.Linear(3, 2),
        )
    def __call__(self, x):
        h = self.l1(x)
        return self.l2(h)


# setup chain
model=MyChain()

# setup optimizer
optimizer = optimizers.SGD() #Stochastic Gradient Descent
optimizer.setup(model)

# git initial gradients for network
model.zerograds()

# -------------------
# compute gradient here...
# -------------------

# update network
optimizer.update()
