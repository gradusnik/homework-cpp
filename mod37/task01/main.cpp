//#include <QApplication>
//#include <QPushButton>
#include "mainWindow.h"


int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QMainWindow window(nullptr);
  Ui::MainWindow form;
  form.setupUi(&window);
  form.displayRezult->setDigitCount(19);
  window.show();

  return QApplication::exec();
}
