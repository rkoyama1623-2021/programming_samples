import sys
from pyqtgraph.Qt import QtGui #from PyQt4 import QtGui
import pyqtgraph

app = QtGui.QApplication(sys.argv) # construct a QApplication (must).

mw = QtGui.QMainWindow()
mw.resize(800,800)
mw.show()
mw.setWindowTitle('Wine Plots')

status=app.exec_()# status get error messages

if not status:# if there is no error
    status="exit."
sys.exit(status)

