#include "widget.h"
#include <QLabel>

Widget::Widget(QString userName, float amount, QWidget *parent)
    : QWidget(parent), userName(userName), amount(amount)
{
    this->layout = new QHBoxLayout();
    this->setLayout(layout);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setPalette(pal);
    this->setVisible(true);
    this->setAutoFillBackground(true);
    this->setFixedSize(QSize(421, 61));
}

void Widget::setUserName(QString userName){
    this->userName = userName;
}

void Widget::setAmount(float amount){
    this->amount = amount;
}
