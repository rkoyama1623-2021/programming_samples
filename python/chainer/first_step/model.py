from __future__ import print_function

import numpy as np
import chainer
from chainer import cuda, Function, gradient_check, Variable, optimizers, serializers, utils
from chainer import Link, Chain, ChainList
import chainer.functions as F
import chainer.links as L

#1. simplest network
# generate links (each link define function for one layer)
l1 = L.Linear(4, 3) # 4->3
l2 = L.Linear(3, 2) # 3->2
# combine multiple links (multiple layer network)
def my_forward(x):
    h = l1(x)
    return l2(h)


# 2. network using class
class MyProc(object):
    def __init__(self):
        self.l1 = L.Linear(4, 3)
        self.l2 = L.Linear(3, 2)

    def forward(self, x):
        h = self.l1(x)
        return self.l2(h)


# 3. network inheriting chainer.Chain
## Note that Chain itself inherits Link. It means we can define more complex chains that hold MyChain objects as their child links.
class MyChain(Chain):
    def __init__(self):
        super(MyChain, self).__init__(
            l1=L.Linear(4, 3),
            l2=L.Linear(3, 2),
        )
    def __call__(self, x):
        h = self.l1(x)
        return self.l2(h)



if __name__=="__main__":
    x=chainer.Variable(np.array([[1,2,3,4]],dtype=np.float32))
    c=MyChain()
    y=c(x)
    y.grad = np.ones((1, 2), dtype=np.float32)
    y.backward()
    print("x.grad={0}".format(x.grad))
