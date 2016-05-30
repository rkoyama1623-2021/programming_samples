# -*- coding: utf-8 -*-
import sys
from PyQt4 import QtGui
from PyQt4 import QtCore

class Example(QtGui.QMainWindow):

    def __init__(self):
        super(Example, self).__init__()
        self.initUI()


    def initUI(self):
        exitAction = QtGui.QAction(QtGui.QIcon('exit.png'), 'Exit', self)
        exitAction.setShortcut('Ctrl+Q')
        exitAction.triggered.connect(QtGui.qApp.quit)

        pythonAction = QtGui.QAction(QtGui.QIcon('pythonlogo.png'), 'Python', self)
        pythonAction.setShortcut('Ctrl+P')
        pythonAction.triggered.connect(QtGui.qApp.quit)

        qtInfoAction = QtGui.QAction(QtGui.QIcon('qtlogo.png'), 'qtinfo', self)
        qtInfoAction.setShortcut('Ctrl+I')
        qtInfoAction.setStatusTip('Show Qt info')
        qtInfoAction.triggered.connect(QtGui.qApp.aboutQt)

        self.toolbar = self.addToolBar('toolbar')
        self.toolbar.addAction(exitAction)
        self.toolbar.addAction(pythonAction)
        self.toolbar.addAction(qtInfoAction)

        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Toolbar')
        self.show()

def main():
    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
