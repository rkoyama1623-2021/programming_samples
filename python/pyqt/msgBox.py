#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class UI(QMainWindow):
    def __init__(self):
        super(UI, self).__init__()
        self.initUI()

    def initUI(self):

        # message box
        result = QMessageBox.question(self, 'Message', u"PyQtに慣れましたか?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
 
        if result == QMessageBox.Yes:
            print 'Selected Yes.'
        else:
            print 'Selected No.'  

        # Warning Message box
        QMessageBox.warning(self, "Message", u"something wrong")

        # Information Message box
        QMessageBox.information(self, "Message", "Please contact at hoge@gmail.com")

        # Error Message box
        QMessageBox.critical(self, "Message", "Oh my god.")

        # About box
        QMessageBox.about(self, "About", "Ver1.0")

        self.show()


def main():
    app = QApplication(sys.argv)
    ui = UI()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()

