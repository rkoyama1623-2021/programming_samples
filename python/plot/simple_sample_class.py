import matplotlib.pyplot as plt
import numpy as np

class myplot():
    def __init__(self):
        self.fig, self.ax = plt.subplots()
        self.fig.show()
        # We need to draw the canvas before we start animating...
        self.fig.canvas.draw()
        self._background = self.fig.canvas.copy_from_bbox(self.ax.bbox)

    def plot(self,x,y,*args,**kwargs):
        self.line = self.ax.plot(x, y, animated=True,*args,**kwargs)[0]
    def replot(self,y):
        self.fig.canvas.restore_region(self._background)
        self.line.set_ydata(y)
        self.ax.draw_artist(self.line)
        self.fig.canvas.blit(self.ax.bbox)


if __name__=="__main__":
    import time
    p=myplot()
    x=np.arange(0,2*np.pi,0.1)
    y=np.sin(x)
    p.plot(x,y)
    counter=0
    for i in range(1000):
        y=np.sin(x-counter/100.0)
        p.replot(y)
        # time.sleep(0.001)
        counter+=1




