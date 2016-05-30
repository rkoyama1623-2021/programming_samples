#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
from PyQt4.QtGui import *
from PyQt4.QtCore import *
import datetime

class Example(QMainWindow):
    def __init__(self):
        super(Example, self).__init__()
        self.initUI()
        
    def initUI(self):               
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Radio Button')    

        self.w = QWidget()

        vbox =QVBoxLayout()

        hbox =QHBoxLayout()
        self.b11=QRadioButton("Man")
        self.b12=QRadioButton("Woman")
        self.bg1=QButtonGroup()
        self.bg1.addButton(self.b11)
        self.bg1.addButton(self.b12)
        hbox.addWidget(self.b11)
        hbox.addWidget(self.b12)

        hbox2 =QHBoxLayout()
        self.b21=QRadioButton("Adult")
        self.b22=QRadioButton("Child")
        self.bg2=QButtonGroup()
        self.bg2.addButton(self.b21)
        self.bg2.addButton(self.b22)
        hbox2.addWidget(self.b21)
        hbox2.addWidget(self.b22)

        vbox.addLayout(hbox)
        vbox.addLayout(hbox2)
        self.w.setLayout(vbox)
        self.setCentralWidget(self.w)

        self.show()

def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
