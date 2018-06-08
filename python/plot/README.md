# plot with python
## matplotlib API
### matplotlib.pyplot
pyplot._pylab_helpers.Gcfというシングルトンで図を管理している。
`plt.plot()`や`plt.show()`などで、グラフオブジェクトを明示的に呼び出さなくて良いのはこのシングルトンのおかげ。
シングルトンと言っても、クラス変数に必要なものを格納しているだけで、インスタンスを生成しているわけではない。

### matplotlib.figure.Figure
外枠.  
すべてのグラフを内包している．


### matplotlib.axes.Axes
一つの座標
`matplotlib.axes.Axes`を継承して、様々な座標が作成される。

### matplotlib.axes.AxesSubplot
`matplotlib.axes.Axes`をsubplot用に継承したもの。  
`matplotlib.axes.subplot_class_factory`関数で、動的に生成されるクラス。  
`figure`メンバに、所属する親の`matplotlib.figure.Figure`が格納されている。  


## matplotlib interactively
### functions
- isinteractive()  
returns the interactive setting True|False  
- ion()  
turns interactive mode on  
- ioff()  
turns interactive mode off  
- draw()  
forces a figure redraw  





