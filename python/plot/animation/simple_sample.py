import matplotlib.pyplot as plt
import numpy as np
import time

fig, ax = plt.subplots()
fig.show()
# We need to draw the canvas before we start animating...
fig.canvas.draw()
background = fig.canvas.copy_from_bbox(ax.bbox)

x = np.arange(0, 2*np.pi, 0.1)
y = np.sin(x)
line=ax.plot(x, y, 'r', animated=True)[0]
for i in xrange(1, 2000):
    fig.canvas.restore_region(background)
    line.set_ydata(np.sin(x + i/10.0))
    ax.draw_artist(line)
    fig.canvas.blit(ax.bbox)
