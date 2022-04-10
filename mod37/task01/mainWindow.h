/********************************************************************************
** Form generated from reading UI file 'calForInt02QxywzI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#define SETREZZ(r) QString res = "error"; \
                    if(var2 == 0 or !v1ok or !v2ok) {res = "error";} \
                    else {(r);res = QString::number(rezz);}          \
                    display(res);

#ifndef CALFORINT02QXYWZI_H
#define CALFORINT02QXYWZI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtGlobal>

QT_BEGIN_NAMESPACE

class myDisplay : public QLCDNumber {
    qint64 vMax = 3037000499;
    qint64 var1 = 0;
    qint64 var2 = 0;
    qint64 rezz = 0;
    bool v1ok = false;
    bool v2ok = false;
public:
    myDisplay(QWidget* parent) : QLCDNumber(parent){};
public slots:
    void setVar1(QString);
    void setVar2(QString);
    void setDivideRezult();
    void setMultiplyRezult();
    void setPlusRezult();
    void setSubtractRezult();
};

void myDisplay::setVar1(QString str) {
  var1 = str.toLongLong(&v1ok);
  QString err("error");
  if (!v1ok) display(err);
  else if (var1 > vMax) display(err);
  else display("-");
}
void myDisplay::setVar2(QString str) {
  var2 = str.toLongLong(&v2ok);
  QString err("error");
  if (!v2ok) display(err);
  else if (var2 > vMax) display(err);
  else display("-");
}

void myDisplay::setDivideRezult() {
  SETREZZ(rezz = var1 / var2)
}
void myDisplay::setMultiplyRezult() {
  SETREZZ(rezz = var1 * var2)
}
void myDisplay::setPlusRezult() {
  SETREZZ(rezz = var1 + var2)
}
void myDisplay::setSubtractRezult() {
  SETREZZ(rezz = var1 - var2)
}

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *divideButton;
    QPushButton *subtrButton;
    myDisplay *displayRezult;
    QPushButton *plusButton;
    QPushButton *multiplButton;
    QLineEdit *var1Line;
    QLineEdit *var2Line;

    void setupUi(QMainWindow *MainWindow)
    {
      if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
      MainWindow->resize(981, 489);
      centralwidget = new QWidget(MainWindow);
      centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
      centralwidget->setMinimumSize(QSize(800, 400));
      gridLayout_2 = new QGridLayout(centralwidget);
      gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
      gridLayout = new QGridLayout();
      gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
      divideButton = new QPushButton(centralwidget);
      divideButton->setObjectName(QString::fromUtf8("divideButton"));
      QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
      sizePolicy.setHorizontalStretch(0);
      sizePolicy.setVerticalStretch(0);
      sizePolicy.setHeightForWidth(divideButton->sizePolicy().hasHeightForWidth());
      divideButton->setSizePolicy(sizePolicy);
      QFont font;
      font.setPointSize(14);
      font.setBold(false);
      font.setItalic(false);
      font.setUnderline(false);
      font.setWeight(50);
      font.setStrikeOut(false);
      font.setKerning(true);
      divideButton->setFont(font);
      divideButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

      gridLayout->addWidget(divideButton, 2, 3, 1, 1);

      subtrButton = new QPushButton(centralwidget);
      subtrButton->setObjectName(QString::fromUtf8("subtrButton"));
      sizePolicy.setHeightForWidth(subtrButton->sizePolicy().hasHeightForWidth());
      subtrButton->setSizePolicy(sizePolicy);
      subtrButton->setFont(font);
      subtrButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

      gridLayout->addWidget(subtrButton, 2, 1, 1, 1);

      displayRezult = new myDisplay(centralwidget);
      displayRezult->setObjectName(QString::fromUtf8("displayRezult"));
      displayRezult->setEnabled(true);
      displayRezult->setMinimumSize(QSize(0, 50));
      displayRezult->setFrameShape(QFrame::Box);
      displayRezult->setFrameShadow(QFrame::Plain);
      displayRezult->setLineWidth(2);
      displayRezult->setSegmentStyle(QLCDNumber::Flat);
      displayRezult->setProperty("intValue", QVariant(0));

      gridLayout->addWidget(displayRezult, 1, 0, 1, 4);

      plusButton = new QPushButton(centralwidget);
      plusButton->setObjectName(QString::fromUtf8("plusButton"));
      sizePolicy.setHeightForWidth(plusButton->sizePolicy().hasHeightForWidth());
      plusButton->setSizePolicy(sizePolicy);
      plusButton->setFont(font);
      plusButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

      gridLayout->addWidget(plusButton, 2, 0, 1, 1);

      multiplButton = new QPushButton(centralwidget);
      multiplButton->setObjectName(QString::fromUtf8("multiplButton"));
      sizePolicy.setHeightForWidth(multiplButton->sizePolicy().hasHeightForWidth());
      multiplButton->setSizePolicy(sizePolicy);
      multiplButton->setFont(font);
      multiplButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

      gridLayout->addWidget(multiplButton, 2, 2, 1, 1);

      var1Line = new QLineEdit(centralwidget);
      var1Line->setObjectName(QString::fromUtf8("var1Line"));
      var1Line->setMinimumSize(QSize(0, 50));
      QFont font1;
      font1.setPointSize(12);
      var1Line->setFont(font1);
      var1Line->setStyleSheet(QString::fromUtf8(""));
      var1Line->setAlignment(Qt::AlignCenter);

      gridLayout->addWidget(var1Line, 0, 0, 1, 2);

      var2Line = new QLineEdit(centralwidget);
      var2Line->setObjectName(QString::fromUtf8("var2Line"));
      var2Line->setMinimumSize(QSize(0, 50));
      var2Line->setFont(font1);
      var2Line->setAlignment(Qt::AlignCenter);

      gridLayout->addWidget(var2Line, 0, 2, 1, 2);


      gridLayout_2->addLayout(gridLayout, 0, 2, 1, 1);

      MainWindow->setCentralWidget(centralwidget);

      retranslateUi(MainWindow);

      QObject::connect(var1Line, &QLineEdit::textChanged, displayRezult, &myDisplay::setVar1);
      QObject::connect(var2Line, &QLineEdit::textChanged, displayRezult, &myDisplay::setVar2);
      QObject::connect(divideButton, &QPushButton::clicked, displayRezult, &myDisplay::setDivideRezult);
      QObject::connect(multiplButton, &QPushButton::clicked, displayRezult, &myDisplay::setMultiplyRezult);
      QObject::connect(plusButton, &QPushButton::clicked, displayRezult, &myDisplay::setPlusRezult);
      QObject::connect(subtrButton, &QPushButton::clicked, displayRezult, &myDisplay::setSubtractRezult);

      //QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
      MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
      divideButton->setText(QCoreApplication::translate("MainWindow", "/\n"
                                                                      "divide", nullptr));
      subtrButton->setText(QCoreApplication::translate("MainWindow", "-\n"
                                                                     "subtract", nullptr));
      plusButton->setText(QCoreApplication::translate("MainWindow", "+\n"
                                                                    "plus", nullptr));
      multiplButton->setText(QCoreApplication::translate("MainWindow", "*\n"
                                                                       "multiply", nullptr));
      var1Line->setPlaceholderText(QCoreApplication::translate("MainWindow", "variable1", nullptr));
      var2Line->setPlaceholderText(QCoreApplication::translate("MainWindow", "variable2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CALFORINT02QXYWZI_H
