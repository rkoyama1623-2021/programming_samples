import sys
import pyqtgraph as pg

pg.plot(x=[0,1,2,4],y=[4,5,9,6])
status=pg.Qt.QtGui.QApplication.instance().exec_() # construct QApplication & execute
sys.exit(status)


'''

import sys
import pyqtgraph as pg

app = pg.Qt.QtGui.QApplication(sys.argv)
pg.plot(x=[0,1,2,4],y=[4,5,9,6])

status=app.exec_()
sys.exit(status)

'''
