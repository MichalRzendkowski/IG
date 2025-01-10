#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

signals:
    void rachunekOpen();

private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
