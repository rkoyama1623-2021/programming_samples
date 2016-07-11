import matplotlib.pyplot as plt
import numpy as np
import time

x = np.arange(0, 4, 0.1)
fig, axes = plt.subplots(2, 2)
for j in range(2):
    for i in range(2):
        ax = axes[j, i]
        ax.plot(x, x**(j*2+i))

fig.set_facecolor((1,1,1,1))

fig.show()



