#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFont>
#include <QHBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QString userName, float amount = 0, QWidget *parent = nullptr, QFont font = QFont("Tahoma", 20));

    void setUserName(QString userName);
    void setAmount(float amount);

protected:
    QHBoxLayout *layout;
    QString userName;
    float amount;
    QFont font;

};

#endif // WIDGET_H
