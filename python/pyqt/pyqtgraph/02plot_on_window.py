import sys
from pyqtgraph.Qt import QtGui #from PyQt4 import QtGui
import pyqtgraph

# make window
app = QtGui.QApplication(sys.argv) # construct a QApplication (must).

mw = QtGui.QMainWindow()
mw.resize(800,800)
mw.setWindowTitle('my qt window')

# make view
view = pyqtgraph.GraphicsLayoutWidget()
# view.show()
mw.setCentralWidget(view)
mw.show()

# make plot area
w1 = view.addPlot(title = "my plot area")

# plot data
# mkPen(color,width,name)
w1.addLegend(offset=(0, 0))
w1.plot([0,1,2,3,4],[3,6,5,8,7],pen=pyqtgraph.mkPen(1, width=1),name="hoge")
w1.plot([0,1,2,3,4],[5,7,6,2,9],pen=pyqtgraph.mkPen(2, width=1),name="fuga")

status=app.exec_()# status get error messages

if not status:# if there is no error
    status="exit."
sys.exit(status)

