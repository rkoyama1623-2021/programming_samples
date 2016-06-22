import pyqtgraph, sys

app = pyqtgraph.Qt.QtGui.QApplication([])
view = pyqtgraph.GraphicsLayoutWidget()

def my_clicked():
    print("button click")

def my_clicked2():
    print("button click 2")

def my_item():
    prox = pyqtgraph.Qt.QtGui.QGraphicsProxyWidget()
    btn = pyqtgraph.Qt.QtGui.QPushButton("+")
    btn.setCheckable(True)
    btn.setChecked(True)
    btn.setMaximumHeight(15)
    btn.setMaximumWidth(15)
    prox.setWidget(btn)
    return prox

def main(use_btn=True):
    for row in range(3):
        cur_row_layout = view.addLayout(row,0)
        if use_btn:
            prox2 = my_item()
            prox2.widget().clicked.connect(my_clicked2)
            cur_row_layout.addItem(prox2, row=0, col=0)
        for col in range(5):
            cur_col_layout = cur_row_layout.addLayout(row=0, col=col+1)
            cur_col_layout.addPlot(name="r"+str(row)+"c"+str(col), row=0, col=0)
            if use_btn:
                prox = my_item()
                prox.widget().clicked.connect(my_clicked)
                cur_col_layout.addItem(prox, row=1, col=0)
    view.show()

main(use_btn=False if len(sys.argv) > 1 else True)
pyqtgraph.Qt.QtGui.QApplication.instance().exec_()
