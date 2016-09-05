#include <qapplication.h>
#include <qwidget.h>

#include <qlabel.h>

#include <qpushbutton.h>
#include <qfont.h>

int main(int argc, char **argv){
  QApplication window(argc, argv);
  QWidget *mainwindow = new QWidget;

  //make main window
  mainwindow->setWindowTitle("window title");
  mainwindow->setMaximumSize(500,300);
  mainwindow->setMinimumSize(250,150);
  mainwindow->resize(400,240);

  //put label on mainwindow
  QLabel *my_label = new QLabel(mainwindow);
  my_label->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  my_label->setText("Hello World.\nIt's fun to creat a program.");
  my_label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
  my_label->setGeometry(50,10,300,50);

  //put button on mainwindow
  QPushButton *my_button = new QPushButton("Quit", mainwindow);
  my_button->setGeometry(150,100,100,50);
  my_button->setFont(QFont("Times", 20, QFont::Bold));
  QObject::connect(my_button, SIGNAL(clicked()), qApp, SLOT(quit()));

  //window.setMainWidget(mainwindow); //Qt3
  mainwindow->show();
  return window.exec();
}
