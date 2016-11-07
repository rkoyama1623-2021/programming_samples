# -*- coding:utf-8 -*-
""""
ax.legend(loc=(0,0))
legend = ax.legend()
- legend.get_frame()
  ectangle surrounding the legend.
  facecolor, edgecolor, ...
- legend.get_texts()
  text of legend
- legend.get_lines()
  each line in legend
- legend.get_edgecolor()

plt.ion() # start interactive mode
plt.ioff() # stop interactive mode
plt.isinteractive()
plt.draw()
"""

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10)
y_sin = np.sin(x)
y_cos = np.cos(x)

fig = plt.figure()
ax = fig.add_subplot(111)

ax.plot(x, y_sin, label="sin")
ax.plot(x, y_cos, label="cos")

legend = ax.legend()
frame = legend.get_frame()
frame.set_edgecolor([1,1,1,1])
plt.draw()
plt.show()


