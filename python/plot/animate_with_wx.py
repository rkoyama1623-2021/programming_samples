#coding:utf-8
import numpy as np
import matplotlib
matplotlib.use('WXAgg')
import matplotlib.pyplot as plt

loop=0
def updateCallBack(idleevent):
    global loop
    x=np.arange(0,2*np.pi,0.1)
    y=np.sin(x+loop*0.05)
    ax.cla()
    ax.plot(x,y)
    ax.set_title("loop: %d" % loop)
    ax.set_ylim([-1.2, 1.2])
    fig.canvas.draw_idle() # draw() only if idle; defaults to draw but backends can overrride
    # fig.canvas.draw() #render the figure
    loop+=1

if __name__=="__main__":
    fig = plt.figure()
    fig.suptitle("animated function", fontsize=18)
    ax = fig.add_subplot(111)

    import wx
    wx.EVT_IDLE(wx.GetApp(), updateCallBack) # event callback
    plt.show()
