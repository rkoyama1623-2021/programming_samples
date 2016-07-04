import numpy as np
import scipy as sp

twopi=2.0*np.pi
def NonAuto(x,t=0,gamma=1.0,omega=1.0,eps=1.0,omega2=np.sqrt(2.0)):
    """
    d2x0/dt2 + gamma*dx0/dt + (omega**2)*x0 = f(t)
    ->
    dx0/dt=x1
    dx1/dt=-gamma*x1 - (omega**2)*x0
    """
    def ft(t):
        return eps*np.cos(omega2*t)

    x0 = x[1]
    x1 = -gamma*x[1] -(omega**2)*x[0] - ft(t)
    return np.array([x0,x1])

