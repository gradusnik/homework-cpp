#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QIcon>
#include <QSpinBox>
#include <iostream>
#include <QPainter>

void changeIcon(QPushButton* butt, const QIcon& in_ic) {
  butt->setIcon(in_ic);
  butt->repaint();
}

int main(int argc, char *argv[]) {

  QApplication app1(argc, argv);

  QIcon ic01("D:\\icons\\icGreen.png");
  QIcon ic02("D:\\icons\\icYellow.png");
  QIcon ic03("D:\\icons\\icRed.png");
  QIcon icArr[] = {ic01, ic02, ic03};

  auto window01 = new QWidget;
  auto layout01 = new QVBoxLayout(window01);

  QPushButton* button01 = new QPushButton(ic01,"", window01);
  QSlider slider01(Qt::Horizontal, window01);
  QSpinBox spinbox01;

  window01->setLayout(layout01);
  layout01->addWidget(button01, 2);
  layout01->addWidget(&slider01, 2);
  layout01->addWidget(&spinbox01);

  slider01.setTickPosition(QSlider::TicksBelow);
  slider01.setTickInterval(10);

  window01->setWindowTitle("topWidget");
  window01->resize(500, 500);

  window01->show();

  QObject::connect(&slider01, &QSlider::valueChanged, &spinbox01, &QSpinBox::setValue);
  QObject::connect(&slider01, &QSlider::valueChanged, [button01, icArr](int _x){
      if (_x == 33) changeIcon(button01, icArr[0]);
      if (_x == 34 || _x == 65) changeIcon(button01, icArr[1]);
      if (_x == 66) changeIcon(button01, icArr[2]);
  });

  return QApplication::exec();
}
