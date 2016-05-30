#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
from PyQt4 import QtGui
from PyQt4 import QtCore

value=0
bar=None

def countup():
    global value
    global bar
    if value<=100:
        value+=5
        bar.setValue(value)

def main():
    app = QtGui.QApplication(sys.argv)
    w = QtGui.QWidget()
    w.resize(250, 150)
    w.setWindowTitle('ProgressBarSample')

    # Create progressBar. 
    global bar
    bar = QtGui.QProgressBar(w)
    bar.resize(200,30)    
    bar.setValue(0)
    bar.move(20,50)

    timer = QtCore.QTimer()
    QtCore.QObject.connect(timer,QtCore.SIGNAL("timeout()"), countup)
    timer.start(1000)

    w.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
