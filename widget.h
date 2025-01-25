#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFont>
#include <QHBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QString userName, float amount = 0, QWidget *parent = nullptr);

    void setUserName(QString userName);
    void setAmount(float amount);

protected:
    QHBoxLayout *layout;
    QString userName;
    float amount;
};

#endif // WIDGET_H
